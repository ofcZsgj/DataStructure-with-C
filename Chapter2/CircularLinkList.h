//
// Created by 左手工匠 on 2019/2/3.
//

#ifndef CHAPTER2_0_CIRCULARLINKLIST_H
#define CHAPTER2_0_CIRCULARLINKLIST_H

#include <stdlib.h>
#include <stdio.h>
#include "DataElement.h"

/********************************************************************
 *  Project:数据结构第第二章循环链表的定义和实现
 *  Function:循环链表的最大特点是尾节点的指针域指向第一个结点
 *  Description:优点是能通过任意结点遍历整个链表结构
 *  Author:左手工匠
 ********************************************************************
 *  Copyright 2019 by 左手工匠
 ********************************************************************/

typedef struct CircularNode {
    ElementType data;
    struct CircularNode *next;
} CircularNode;

typedef struct CircularLinkList {
    CircularNode *next;
    int length;
} CircularLinkList;

/** 循环链表初始化 */
void InitCircularLinkList(CircularLinkList *clList, ElementType *dataArray, int length);

/** 在循环链表的指定位置插入元素 */
void InsertCircularLinkList(CircularLinkList *clList, int pos, ElementType element);

void PrintCircularLinkList(CircularLinkList *clList);

#endif //CHAPTER2_0_CIRCULARLINKLIST_H
