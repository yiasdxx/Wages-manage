
#ifndef _InitEmployee_H
#define _InitEmployee_H

#include "Node_Init.h"

void InitEmployee(struct Node *head)
{
    FILE *fp=fopen("Employee_info.txt","r");
    if(fp == NULL)
    {
        printf("Can not find the file!\n");
        exit(0);
    }
    
    // 备份 Employee_info.txt 到 Employee_Infor_history.txt
    FILE *fb = fopen("Employee_Info_history.txt","w");
    if (fb != NULL) {
        char line[1024];
        while (fgets(line, sizeof(line), fp) != NULL) {
            fputs(line, fb);
        }
        fflush(fb);
        fclose(fb);
        rewind(fp); // 回到文件开头
    } else {
        rewind(fp);
    }

    int num;
    char team[20];
    char name[20];
    char gender[10];
    long long id;
    int wages;
    Node *pmove=head;

    while(fscanf(fp,"%d %s %s %s %lld %d",&num,team,name,gender,&id,&wages) != EOF)
    {
        struct Node *newnode=CreatNode(num,team,name,gender,id,wages);
        pmove->next=newnode;
        pmove=newnode;
    }
    printf("员工工资信息录入成功！\n");
    fclose(fp);
}
#endif