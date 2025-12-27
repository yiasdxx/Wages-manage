#ifndef _EmployAmount_H
#define _EmployAmount_H

#include "Node_Init.h"

//返回总员工数量
int EmployeeAmount(Node *head)
{
    Node *pmove=head->next;
    int count=0;
    while(pmove != NULL)
    {
        pmove=pmove->next;
        count++;
    }

    return count;
}

#endif