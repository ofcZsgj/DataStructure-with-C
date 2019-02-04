//
// Created by ���ֹ��� on 2019/2/3.
//

#ifndef CHAPTER2_0_CIRCULARLINKLIST_H
#define CHAPTER2_0_CIRCULARLINKLIST_H

#include <stdlib.h>
#include <stdio.h>
#include "DataElement.h"

/********************************************************************
 *  Project:���ݽṹ�ڵڶ���ѭ������Ķ����ʵ��
 *  Function:ѭ�����������ص���β�ڵ��ָ����ָ���һ�����
 *  Description:�ŵ�����ͨ�������������������ṹ
 *  Author:���ֹ���
 ********************************************************************
 *  Copyright 2019 by ���ֹ���
 ********************************************************************/

typedef struct CircularNode {
    ElementType data;
    struct CircularNode *next;
} CircularNode;

typedef struct CircularLinkList {
    CircularNode *next;
    int length;
} CircularLinkList;

/** ѭ�������ʼ�� */
void InitCircularLinkList(CircularLinkList *clList, ElementType *dataArray, int length);

/** ��ѭ�������ָ��λ�ò���Ԫ�� */
void InsertCircularLinkList(CircularLinkList *clList, int pos, ElementType element);

/** ɾ��������ָ��λ�õ�Ԫ�� */
ElementType DeleteCircularLinkList(CircularLinkList *clList, int pos);

void PrintCircularLinkList(CircularLinkList *clList);

#endif //CHAPTER2_0_CIRCULARLINKLIST_H
