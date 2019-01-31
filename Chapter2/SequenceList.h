//
// Created by ���ֹ��� on 2019/1/28.
//

#include<stdio.h>
#include<stdlib.h>
#include"DataElement.h"

#ifndef CHAPTER2_0_SEQUENCELIST_H
#define CHAPTER2_0_SEQUENCELIST_H

#define FALSE 0
#define TRUE 1

/********************************************************************
 *  Project:���ݽṹ�ڶ���
 *  Function:��������Ԫ��
 *  Description:
 *  Author:���ֹ���
 ********************************************************************
 *  Copyright 2019 by ���ֹ���
 ********************************************************************/

/**
 * ��ʼ��˳���
 * @param seqList    Ҫ��ʼ����˳���
 * @param elemArray  ��ʼ��ʱҪ��ӵ�Ԫ����������
 * @param length     ��ʼ��ʱ��ӵ�Ԫ�ظ���
 */
void InitList(SeqList *seqList, ElementType *elemArray, int length);

/**
 * ��˳���ָ�����±����Ԫ��
 * @param seqList    Ҫ��ʼ����˳���
 * @param index      Ҫ������±�
 * @param element    Ҫ�����Ԫ��
 */
void InsertElement(SeqList *seqList, int index, ElementType element);

/**
 * ɾ��˳�����ָ���±��Ԫ��
 * @param   Ҫ������˳���
 * @param   Ҫɾ��Ԫ�ص��±�
 * @return  ����ɾ����Ԫ��,��ɾ��ʧ��,����NULL
 */
ElementType *DeleteElement(SeqList *seqList, int index);

/**
 * ����˳�����ָ���±��Ԫ��
 * @param   Ҫ������˳���
 * @param   Ҫ����Ԫ�ص��±�
 * @return  ����ָ���±��Ԫ��,������ʧ��,����NULL
 */
ElementType *GetElement(SeqList *seqList, int index);

/**����˳���ĳ���*/
int GetLength(SeqList *seqList);

/**����˳����Ƿ�Ϊ��*/
int IsEmpty(SeqList *seqList);

/**���˳���*/
void ClearList(SeqList *seqList);

/** ��ӡ˳���*/
void PrintList(SeqList *seqList);

#endif //CHAPTER2_0_SEQUENCELIST_H
