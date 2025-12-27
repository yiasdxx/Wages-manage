#ifndef _print_H
#define _print_H

#include "Node_Init.h"

//6.浏览员工信息
void print(Node *head)
{
    Node *pmove=head->next;
    while(pmove != NULL)
    {
        printf("%d\t%s\t%s\t%s\t%lld\t%d\n",
            pmove->data.num,
            pmove->data.team,
            pmove->data.name,
            pmove->data.gender, 
            pmove->data.id,            
            pmove->data.wages);
        pmove=pmove->next;
    }
}

#endif