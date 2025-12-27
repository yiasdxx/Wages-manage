#ifndef _saveInfo_H
#define _saveInfo_H

#include "Node_Init.h"
#include "EmployeeAmount.h"
#include "Count.h"

//8.打印新文件
void saveInfo(Node* head)
{
    FILE *fp=fopen("Employee_info.txt","w");
    FILE *fs = fopen("Employee_show.txt","w");
    if(fp == NULL)
    {
        printf("cannot find the file!\n");
        exit(0);
    }


    int recordN=EmployeeAmount(head);
    struct Node *pmove=head->next;
    for(int i=0;i<recordN;i++){
        if (pmove == NULL) break;
        fprintf(fp,"%d %s %s %s %lld %d\n",
            pmove->data.num,
            pmove->data.team,
            pmove->data.name,
            pmove->data.gender,
            pmove->data.id,
            pmove->data.wages);
        if (fs) {
            fprintf(fs,"%d %s %s %s %lld %d\n",
                pmove->data.num,
                pmove->data.team,
                pmove->data.name,
                pmove->data.gender,
                pmove->data.id,
                pmove->data.wages);
        }
        pmove=pmove->next;
    }

    // 在显示文件末尾追加统计结果
    if (fs) {
        CountWriteStats(head, fs);
    }

    fclose(fp);
    fclose(fs);

    printf("文件创建成功！\n");
}

#endif