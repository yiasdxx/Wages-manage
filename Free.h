#ifndef __FREE_H
#define __FREE_H

#include "Node_Init.h"

void Free(Node *p)
{
    if(p == NULL) return;

    free(p);
}
#endif