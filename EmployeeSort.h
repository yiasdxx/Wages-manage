#ifndef _EmployeeSort_H
#define _EmployeeSort_H

#include "Node_Init.h"

//7.员工工资排序（递减）
void EmployeeSortByWages(struct Node *head, int n)
{
    if (head == NULL || head->next == NULL) return;
    
    Node *current, *nextNode;
    for (int i = 0; i < n - 1; i++) {
        current = head->next;
        for (int j = 0; j < n - i - 1; j++) {
            nextNode = current->next;
            if (nextNode != NULL && current->data.wages < nextNode->data.wages) {
                Employee tempWages = current->data;
                current->data = nextNode->data;
                nextNode->data = tempWages;
            }
            current = current->next;
            if (current == NULL) break;
        }
    }
}

// 按编号升序排序
void EmployeeSortByNum(struct Node *head, int n)
{
    if (head == NULL || head->next == NULL) return;
    Node *current, *nextNode;
    for (int i = 0; i < n - 1; i++) {
        current = head->next;
        for (int j = 0; j < n - i - 1; j++) {
            nextNode = current->next;
            if (nextNode != NULL && current->data.num > nextNode->data.num) {
                Employee temp = current->data;
                current->data = nextNode->data;
                nextNode->data = temp;
            }
            current = current->next;
            if (current == NULL) break;
        }
    }
}

#endif