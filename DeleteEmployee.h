#ifndef _DeleteEmployee_H
#define _DeleteEmployee_H

#include "Node_Init.h"

//3.删除员工信息
void DeleteEmployee(Node *head,int num)
{
    int index=0;
    Node *pmove=head;
    Node *ptemp=NULL;
    while(pmove!=NULL)
    {
        ptemp=pmove;
        pmove=pmove->next;
        if(pmove->data.num == num)
        {   
            ptemp->next=pmove->next;
            free(pmove);
            index=1;
            break;
        }
    }

    if(index == 1) printf("删除成功！\n");
        else printf("删除失败！\n");
}
#endif