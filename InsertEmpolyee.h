
//2.增加员工信息并更新文件(尾插入)

#ifndef _IsertEmployee_H
#define _IsertEmployee_H

#include "Node_Init.h"
#include "Found.h"

int num;
char team[20];
char name[20];
char gender[10];
long long id;
int wages;
//尾插法
void InsertEmpolyee(Node *head,int n)
{
    Node *pmove=head;
    while(pmove != NULL && pmove->next != NULL)
    {
        pmove=pmove->next;
    }

    printf("请输入编号,部门,姓名,性别,身份证号,工资：\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d%s%s%s%lld%d",&num,team,name,gender,&id,&wages);

        if(Found(head,num) != NULL)
        {
            printf("编号:%d的员工已经录入到系统中...\n",id);
            return;
        }
        Node *newEmployee = CreatNode(num, team, name, gender, id, wages);

        pmove->next = newEmployee;
        pmove = newEmployee; 
    }
    
    printf("添加成功!\n");
}
#endif