//
// Created by ���ֹ��� on 2019/1/28.
//

#ifndef CHAPTER2_0_DATAELEMENT_H
#define CHAPTER2_0_DATAELEMENT_H

/********************************************************************
 *  Project:���ݽṹ�ڶ���
 *  Function:��������Ԫ��
 *  Description:
 *  Author:���ֹ���
 ********************************************************************
 *  Copyright 2019 by ���ֹ���
 ********************************************************************/

#define MAX_SIZE 255

//1.��������Ԫ��
//typedef int ElementType;
/*
 *datas{{1,""},{2,""},{3,""}};
 */
typedef struct {
    int id;
    char *name;
} ElementType;

//2.����˳���ṹ
typedef struct {
    ElementType datas[MAX_SIZE];//˳����е�����Ԫ�ؼ���
    int length;                 //��ǰ˳�����Ԫ�ظ���
} SeqList;

#endif //CHAPTER2_0_DATAELEMENT_H
