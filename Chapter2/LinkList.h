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
 *  Description:第一个结点存储的位置叫头指针, 链表每个结点都有后继结点, 链表的优点是高效利用存储空间
 *  Author:左手工匠
 ********************************************************************
 *  Copyright 2019 by 左手工匠
 ********************************************************************/

/**  定义链表的结点, 包括数据域和指针域 */
typedef struct Node {
    ElementType data;      //数据域
    struct Node *next;     //指针域,指向下个结点
} Node;

/**
 * 头结点 ! ! !
 * 注意: 定义链表习惯定义头结点, 以便统一链表结点的插入和删除操作(操作第一个元素时无需改变头指针的地址)
 * 头结点也称首元结点, 最后一个结点称为尾元结点
 */
typedef struct LinkList {
    Node *next;    //头指针(如果链表有头结点, next指向头结点, 没有就指向第一个结点)
    int length;    //链表的长度,初始值为零
} LinkList;

/** 初始化链表 */
void InitLinkList(LinkList *linkList, ElementType *dataArray, int length);

/** 在指定位置pos处插入元素element */
void InsertLinkList(LinkList *linkList, int pos, ElementType element);

/** 删除指定位置的元素并返回该元素的数据 */
ElementType DeleteLinkListElement(LinkList *linkList, int pos);

/** 清空链表 */
void ClearLinkList(LinkList *linkList);

/** 查询指定位置(pos)的元素 */
ElementType GetLinkListElement(LinkList * linkList, int pos);

int IsLinkListEmpty(LinkList *linkList);

void PrintLinkList(LinkList *linkList);

#endif //CHAPTER2_0_LINKLIST_H
