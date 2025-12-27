#ifndef _Found_H
#define _Found_H

#include "Node_Init.h"

//查找指定员工函数
struct Node *Found(Node *head,int num)
{
    Node *pmove=head;
    while(pmove!=NULL)
    {
        if(pmove->data.num == num)
        {   
            return pmove;
        }
        pmove=pmove->next;
    }

    return NULL;
}
#endif