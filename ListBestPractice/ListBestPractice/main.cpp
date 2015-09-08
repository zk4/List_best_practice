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
    for(int i=0;i<count;++i)  addNode(current,va_arg(arg_list,int));
    va_end (arg_list);
}
void printList(Node** current)
{
    while (*current)
    {
        printf("%d,",(*current)->data);
        current=&((*current)->next);
    }
}

void deleteNode(Node** current, int data)
{
    while (*current)
    {
        if((*current)->data==data)
        {
            Node* rear=(*current)->next;
            delete *current;
            *current=rear;
            break;
        }
        current=&((*current)->next);
    }
}

Node* findNode(Node** current, int data)
{
    while (*current) {
        if((*current)->data==data)return  *current;
        current=&((*current)->next);
    }
    return  NULL;
}


int main(int argc, const char * argv[]) {

    Node*  list=NULL;
    addNodes(&list, 7,1,2,3,4,5,6,7);

    
    deleteNode(&list, 2);
    printList(&list);
    
    
    return 0;
}
