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
 *  Description:����ÿ����㶼�к�̽��,������ŵ��Ǵ洢�ռ����ø�Ч
 *  Author:���ֹ���
 ********************************************************************
 *  Copyright 2019 by ���ֹ���
 ********************************************************************/

/**  ��������Ľ��, �����������ָ���� */
typedef struct Node {
    ElementType data;       //������
    struct Node * node;     //ָ����
} Node;

/**
 * ͷ��� ! ! !
 * ע��: ��������ϰ�߶���ͷ���, �Ա�ͳһ������Ĳ����ɾ������
 * ͷ���Ҳ����Ԫ���, ���һ������ΪβԪ���
 */
typedef struct LinkList {
    Node * next;    //ͷָ��(���������ͷ���, nextָ��ͷ���, û�о�ָ���һ�����)
    int length;     //����ĳ���,��ʼֵΪ��
}LinkList;

/** ��ʼ������ */
void InitLinkList(LinkList linkList, ElementType * dataArray, int length);

/** ��ָ��λ��pos������Ԫ��element */
void InsertLinkList(LinkList linkList, int pos, ElementType element);

#endif //CHAPTER2_0_LINKLIST_H
