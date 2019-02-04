//
// Created by ���ֹ��� on 2019/1/31.
//

#ifndef CHAPTER2_0_LINKLIST_H
#define CHAPTER2_0_LINKLIST_H

#include <stdio.h>
#include <stdlib.h>
#include "DataElement.h"

/********************************************************************
 *  Project:���ݽṹ�ڶ���
 *  Function:��������������͵Ķ����ʵ��
 *  Description:��һ�����洢��λ�ý�ͷָ��, ����ÿ����㶼�к�̽��, ������ŵ��Ǹ�Ч���ô洢�ռ�
 *  Author:���ֹ���
 ********************************************************************
 *  Copyright 2019 by ���ֹ���
 ********************************************************************/

/**  ��������Ľ��, �����������ָ���� */
typedef struct Node {
    ElementType data;      //������
    struct Node *next;     //ָ����,ָ���¸����
} Node;

/**
 * ͷ��� ! ! !
 * ע��: ��������ϰ�߶���ͷ���, �Ա�ͳһ������Ĳ����ɾ������(������һ��Ԫ��ʱ����ı�ͷָ��ĵ�ַ)
 * ͷ���Ҳ����Ԫ���, ���һ������ΪβԪ���
 */
typedef struct LinkList {
    Node *next;    //ͷָ��(���������ͷ���, nextָ��ͷ���, û�о�ָ���һ�����)
    int length;    //����ĳ���,��ʼֵΪ��
} LinkList;

/** ��ʼ������ */
void InitLinkList(LinkList *linkList, ElementType *dataArray, int length);

/** ��ָ��λ��pos������Ԫ��element */
void InsertLinkList(LinkList *linkList, int pos, ElementType element);

/** ɾ��ָ��λ�õ�Ԫ�ز����ظ�Ԫ�ص����� */
ElementType DeleteLinkListElement(LinkList *linkList, int pos);

/** ������� */
void ClearLinkList(LinkList *linkList);

/** ��ѯָ��λ��(pos)��Ԫ�� */
ElementType GetLinkListElement(LinkList *linkList, int pos);

int IsLinkListEmpty(LinkList *linkList);

void PrintLinkList(LinkList *linkList);

#endif //CHAPTER2_0_LINKLIST_H
