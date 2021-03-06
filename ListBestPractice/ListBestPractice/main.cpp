//
//  main.cpp
//  ListBestPractice
//
//  Created by zk on 9/8/15.
//  Copyright (c) 2015 zk. All rights reserved.
//

#include <iostream>

struct Node
{
    Node* next;
    int   data;
} **List;


void addNode(Node** current,int data)
{
    *current=new Node{*current,data};
}

//when you are using primitves,use count,if object,use null to identity the end :)
void addNodes(Node** current,int count , ...)
{
    va_list arg_list;
    va_start (arg_list, count);
    for(int i=0;i<count;++i,current=&(*current)->next)
        addNode(current,va_arg(arg_list,int));

    va_end (arg_list);
}


void printList(Node* current)
{
    for(; current; current=(current->next) )
        printf("%d,",current->data);
}

void deleteNode(Node** current, int data)
{
    for(; *current; current=&((*current)->next) )
    {
        if((*current)->data==data)
        {
            Node* rear=(*current)->next;
            delete *current;
            *current=rear;
            break;
        }
    }
}

Node* findNode(Node* current, int data)
{
     for(; current; current=(current->next) )
        if(current->data==data)return  current;

    return  NULL;
}

Node* reverse(Node** head) {
    Node* new_root = NULL;
    Node* next=NULL;
    while (*head) {
        next = (*head)->next;
        (*head)->next = new_root;
        new_root = *head;
        *head = next;
    }
    *head=new_root;
    return new_root;
}

Node* findCircleStart(Node* head)
{
    Node *step1,*step2;
    step1=head;
    step2=head->next;
    while (step1) {
        if(!step2->next)return NULL;
        step2=step2->next->next;
        step1=step1->next;
        if(step1==step2)
            return  step1;
       
    }
    return NULL;

}



int main(int argc, const char * argv[]) {

    Node*  list=NULL;
 
    addNodes(&list, 11,1,2,11,3,4,5,6,7,8,9,10);
    
    
    printf("test delete..\n");
    deleteNode(&list, 11);
    printList(list);
    

    printf("\ntest reverse..\n");
    printList(reverse(&list));
    //reverse back
    reverse(&list);
    
    printf("\nmake ring at 10..\n");
    findNode(list, 10)->next=findNode(list, 1);
    auto ringAt=findCircleStart(list);
    printf("find ring at %d",findCircleStart(list)?ringAt->data:-1);
    
    printf("\nbreak ring..\n");
    findCircleStart(list)->next=NULL;
    printf("is ring? %s",findCircleStart(list)?"yes":"no");
    
    
    return 0;
}
