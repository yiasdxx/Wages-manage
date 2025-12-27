/*
（输入密码进入系统）
0. 退出系统
1. 录入员工工资信息
2. 增加员工信息
3. 删除员工信息
4. 查找员工信息：按部门搜索，按工资范围搜索，查找具体姓名
5. 改动指定员工信息
6. 浏览工资信息
7. 员工工资排序
8. 创建并更新文件
9.统计并打印最大、最小、平均值、中位数和极差
10. 追加文件内容（年月日员工总数）
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "InitEmployee.h"
#include "EmployeeSort.h"
#include "ChangeEmployee.h"
#include "SearchEmployee.h"
#include "DeleteEmployee.h"
#include "InsertEmpolyee.h"
#include "saveInfo.h"
#include "EmployeeAmount.h"
#include "print.h"
#include "Free.h"
#include "Count.h"


int num;
char team[20];
char name[20];
char gender[10];
long long id;
int wages;
int Password=114514;
int pass,count=0;
int init=0;

void main()
{
    //密码验证
    printf("请输入管理员密码：\n");
    while(count<=3)
    {
        scanf("%d",&pass);
        if(pass != Password)
        {
            printf("密码错误！\n");
        }
        else
        {
            printf("密码正确！\n");
            printf("正在进入系统....\n");
            break;
        }
        count++;
        if(count==3) printf("还剩一次机会\n");
    }
    
    if(count > 3)
    {
        printf("无法进入系统...\n");
        return;
    }
    else
    {
        struct Node *head=creatlist();
        printf("\n====================================\n");
        printf("   员工工资管理系统\n");
        printf("====================================\n");

        printf("根据以下功能，请输入0-8：\n");
        printf( "0. 退出系统\n"
                "1. 初始化员工工资信息\n"
                "2. 增加员工信息\n"
                "3. 删除员工信息\n"
                "4. 查找员工信息\n"
                "5. 改动指定员工信息\n"
                "6. 打印工资表\n"
                "7. 员工排序\n"
                "8.打印新文件\n"
                "9.统计并打印最大、最小、平均值、中位数和极差\n");

        while(1)
        {
            int mode;
            scanf("%d",&mode);
            
            switch(mode)
            {
                //1. 录入员工工资信息
                case 1:
                    InitEmployee(head);
                    printf("编号\t部门\t姓名\t性别\t身份证号\t工资\n");
                    print(head);
                    init=1;
                    break;
                //2.增加员工信息(尾插入)
                case 2:
                    {int n;
                    printf("请输入你要增加的员工数量：");
                    scanf("%d",&n);
                    InsertEmpolyee(head,n);
                    break;}
                //3.删除员工信息
                case 3:
                    printf("请输入你想要删除的员工编号：");
                    scanf("%d",&num);
                    DeleteEmployee(head,num);
                    break;
                //4.查找员工信息
                case 4:
                    printf("请选择你要搜索的目标\n");
                    printf("1. 按部门搜索\n");
                    printf("2. 按工资范围搜索\n");
                    printf("3. 按编号搜索\n");
                    printf("4. 按姓名搜索\n");
                    int op1;
                    scanf("%d",&op1);
                    switch(op1)
                    {
                        case 1:
                            printf("输入部门：");
                            scanf("%s",team);
                            SearchEmployee_team(head,team);
                        break;
                        case 2:{
                            int wages1,wages2;
                            printf("输入查询的工资范围：\n");
                            scanf("%d%d",&wages1,&wages2);
                            SearchEmployee_Wages(head,wages1,wages2);
                        break;}
                        case 3:
                            printf("请输入你想要查找的员工编号：");
                            scanf("%d",&num);
                            SearchEmployee_num(head,num);
                        break;
                        case 4:
                            printf("请输入你想要查找的员工姓名：");
                            scanf("%s",name);
                            SearchEmployee_name(head,name);
                        break;
                        default:
                            printf("操作错误\n");
                        break;
                    }
                    
                    break;
                //5.改动指定员工信息
                case 5:
                    printf("请输入你想要改动员工的num:");
                    scanf("%d",&num);
                    ChangeEmployee(head,num);
                    break;
                //6.浏览员工信息
                case 6:
                    print(head);
                    break;
                //7.排序
                case 7:{
                    int sum;
                    sum=EmployeeAmount(head);
                    printf("请选择你要排序的方式\n");
                    printf("1. 按工资排序（递减）\n");
                    printf("2. 按编号排序（递增）\n");
                    int op2;
                    scanf("%d",&op2);
                    switch(op2)
                    {
                        case 1:
                            EmployeeSortByWages(head,sum);
                            printf("排序成功！\n");
                            print(head);
                        break;
                        case 2:
                            EmployeeSortByNum(head,sum);
                            printf("排序成功！\n");
                            print(head);
                        break;
                        default:
                            printf("操作错误\n");
                    }
                    break;}
                //创建新文件
                case 8:
                    if(init == 1)
                        saveInfo(head);
                    else 
                        printf("未进行初始化操作！\n");
                    break;
                case 9:
                    //统计并打印最大、最小、平均值、中位数和极差
                    CountStats(head);
                    break;
                //0.退出系统
                case 0:
                    return;

                default:
                    printf("操作错误，请重新输入！\n");
            }        
        }

        Free(head);
    }
}
    