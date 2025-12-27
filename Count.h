#ifndef _Count_H
#define _Count_H

#include "Node_Init.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

// 统计并打印最大、最小、平均值、中位数和极差
void CountStats(Node *head)
{
	if (head == NULL) {
		printf("链表为空\n");
		return;
	}
	int count = 0;
	Node *p = head->next;
	if (p == NULL) {
		printf("没有员工信息\n");
		return;
	}

	for (Node *t = p; t != NULL; t = t->next) count++;
	int *arr = (int *)malloc(sizeof(int) * count);
	long long sum = 0;
	int index = 0;
	int max = INT_MIN;
	int min = INT_MAX;
	for (Node *t = p; t != NULL; t = t->next) {
		int w = t->data.wages;
		arr[index++] = w;
		sum += w;
		if (w > max) max = w;
		if (w < min) min = w;
	}

	// 排序求中位数
	for (int i = 0; i < count - 1; i++) {
		for (int j = i + 1; j < count; j++) {
			if (arr[i] > arr[j]) {
				int tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}

	double avg = (double)sum / (double)count;//平均数
	double median;//中位数
	if (count % 2 == 1) {
		median = arr[count / 2];
	} else {
		median = (arr[count/2 - 1] + arr[count/2]) / 2.0;
	}

	int range = max - min;//极差

	printf("员工工资统计：\n");
	printf("  总人数: %d\n", count);
	printf("  最高工资: %d\n", max);
	printf("  最低工资: %d\n", min);
	printf("  平均工资: %.2f\n", avg);
	printf("  中位数: %.2f\n", median);
	printf("  极差: %d\n", range);

	free(arr);
}

// 将统计结果写入指定文件
void CountWriteStats(Node *head, FILE *out)
{
	if (out == NULL) return;
	if (head == NULL) {
		fprintf(out, "链表为空\n");
		return;
	}
	int count = 0;
	Node *p = head->next;
	if (p == NULL) {
		fprintf(out, "没有员工信息\n");
		return;
	}

	for (Node *t = p; t != NULL; t = t->next) count++;
	int *arr = (int *)malloc(sizeof(int) * count);
	long long sum = 0;
	int index = 0;
	int max = INT_MIN;
	int min = INT_MAX;
	for (Node *t = p; t != NULL; t = t->next) {
		int w = t->data.wages;
		arr[index++] = w;
		sum += w;
		if (w > max) max = w;
		if (w < min) min = w;
	}

	// 排序求中位数
	for (int i = 0; i < count - 1; i++) {
		for (int j = i + 1; j < count; j++) {
			if (arr[i] > arr[j]) {
				int tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}

	double avg = (double)sum / (double)count;//平均数
	double median;//中位数
	if (count % 2 == 1) {
		median = arr[count / 2];
	} else {
		median = (arr[count/2 - 1] + arr[count/2]) / 2.0;
	}

	int range = max - min;//极差

	// 输出统计时间
	time_t now = time(NULL); //获取当前时间戳
	struct tm *time = localtime(&now);//转换为本地时间
	char timestr[64] = "";
	if (time) strftime(timestr, sizeof(timestr), "%Y-%m-%d %H:%M:%S", time);//格式化时间字符串
	fprintf(out, "\n统计时间: %s\n", timestr);
	fprintf(out, "--- 统计结果 ---\n");
	fprintf(out, "  总人数: %d\n", count);
	fprintf(out, "  最高工资: %d\n", max);
	fprintf(out, "  最低工资: %d\n", min);
	fprintf(out, "  平均工资: %.2f\n", avg);
	fprintf(out, "  中位数: %.2f\n", median);
	fprintf(out, "  极差: %d\n", range);

	free(arr);
}

#endif