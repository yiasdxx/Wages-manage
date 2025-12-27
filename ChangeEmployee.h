#ifndef _ChangeEmployee_H
#define _ChangeEmployee_H


#include "Node_Init.h"
#include "Found.h"

//5.改动指定员工工资信息
void ChangeEmployee(Node *head,int num)
{
    Node *pid=Found(head,num);
    if(pid != NULL)
    {
        int newwages;
        scanf("%d",&newwages);
        pid->data.wages=newwages;
        printf("修改成功！\n");
    }
    else
        printf("未找到此人！\n");
}
//test
#endif