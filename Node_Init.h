#ifndef _Node_Init_H
#define _Node_Init_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Employee
{   
    int num;
    char team[20];
    char name[20];
    char gender[10];
    long long id;
    int wages;
}Employee;

typedef struct Node
{
    Employee data;

    struct Node *next;
}Node;

struct Node *creatlist()
{
    Node *head=(Node *)malloc(sizeof(Node));
    head->next=NULL;

    return head;
}

struct Node *CreatNode(int num,char team[],char name[],char gender[],long long id,int wages)
{
    Node *p=(Node *)malloc(sizeof(Node));
    p->data.num=num;
    p->data.id=id;
    strcpy(p->data.team,team);
    strcpy(p->data.name,name);
    strcpy(p->data.gender,gender);
    p->data.wages=wages;
    p->next=NULL;

    return p;
}
#endif