#ifndef _SearchEmployee_H
#define _SearchEmployee_H

#include "Node_Init.h"
#include "Found.h"
#include <string.h>

//部门查找
void SearchEmployee_team(Node *head,char team[])
{
    int index=0;
    Node *pmove=head->next;
    while(pmove != NULL)
    {
        if(strcmp(pmove->data.team,team) == 0)
        {
            printf("%d %s %s %s %lld %d\n",
                pmove->data.num,
                pmove->data.team,
                pmove->data.name,
                pmove->data.gender,
                pmove->data.id,
                pmove->data.wages);
            index=1;
        }
        pmove=pmove->next;
    }
    if(index == 1) printf("查找成功！\n");
        else printf("查找失败！\n");
}

//工资范围查找
void SearchEmployee_Wages(Node *head,int l,int r)
{
    int index=0;
    Node *pmove=head->next;
    while(pmove!=NULL)
    {
        if(pmove->data.wages >= l && pmove->data.wages <= r)
        {
            printf("%d %s %s %s %lld %d\n",
                pmove->data.num,
                pmove->data.team,
                pmove->data.name,
                pmove->data.gender,
                pmove->data.id,
                pmove->data.wages);
            index=1;
        }
        pmove=pmove->next;
    }
    if(index == 1) printf("查找成功！\n");
        else printf("查找失败！\n");
}

//3.编号查找
void SearchEmployee_num(Node *head,int num)
{
    Node *pnum=Found(head,num);
    if(pnum != NULL)
    {
        printf("查找成功：\n");
        printf("%d %s %s %s %lld %d\n",
            pnum->data.num,
            pnum->data.team,
            pnum->data.name,
            pnum->data.gender,
            pnum->data.id,
            pnum->data.wages);
    }
    else
        printf("查找失败!\n");
}
//4.姓名查找
void SearchEmployee_name(Node *head,char name[])
{
    int index=0;
    Node *pmove=head->next;
    while(pmove != NULL)
    {
        if(strcmp(pmove->data.name,name) == 0)
        {
            printf("%d %s %s %s %lld %d\n",
                pmove->data.num,
                pmove->data.team,
                pmove->data.name,
                pmove->data.gender,
                pmove->data.id,
                pmove->data.wages);
            index=1;
        }
        pmove=pmove->next;
    }
    if(index == 1) printf("查找成功！\n");
        else printf("查找失败！\n");
}

#endif