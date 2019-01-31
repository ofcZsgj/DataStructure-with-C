//
// Created by 左手工匠 on 2019/1/31.
//

#ifndef CHAPTER2_0_LINKLIST_H
#define CHAPTER2_0_LINKLIST_H

#include <stdio.h>
#include <stdlib.h>
#include "DataElement.h"

/********************************************************************
 *  Project:数据结构第二章
 *  Function:链表抽象数据类型的定义和实现
 *  Description:链表每个结点都有后继结点,链表的优点是存储空间利用高效
 *  Author:左手工匠
 ********************************************************************
 *  Copyright 2019 by 左手工匠
 ********************************************************************/

/**  定义链表的结点, 包括数据域和指针域 */
typedef struct Node {
    ElementType data;       //数据域
    struct Node * node;     //指针域
} Node;

/**
 * 头结点 ! ! !
 * 注意: 定义链表习惯定义头结点, 以便统一链表结点的插入和删除操作
 * 头结点也称首元结点, 最后一个结点称为尾元结点
 */
typedef struct LinkList {
    Node * next;    //头指针(如果链表有头结点, next指向头结点, 没有就指向第一个结点)
    int length;     //链表的长度,初始值为零
}LinkList;

/** 初始化链表 */
void InitLinkList(LinkList linkList, ElementType * dataArray, int length);

/** 在指定位置pos处插入元素element */
void InsertLinkList(LinkList linkList, int pos, ElementType element);

#endif //CHAPTER2_0_LINKLIST_H
