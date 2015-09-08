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
void reverse(Node** current,int step) {
   
}
void reverse(Node** head) {
    Node* new_root = NULL;
    Node* next=NULL;
    while (*head) {
        next = (*head)->next;
        (*head)->next = new_root;
        new_root = *head;
        *head = next;
    }
    *head=new_root;
    
}




int main(int argc, const char * argv[]) {

    Node*  list=NULL;
 
    addNodes(&list, 10,1,2,3,4,5,6,7,8,9,10);
    
    
    printf("test delete..\n");
    deleteNode(&list, 2);
    printList(list);
    

    printf("test reverse..\n");
    reverse(&list);
    printList(list);
    
    
    return 0;
}
