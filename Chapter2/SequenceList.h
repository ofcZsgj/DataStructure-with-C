//
// Created by 左手工匠 on 2019/1/28.
//

#include<stdio.h>
#include<stdlib.h>
#include"DataElement.h"

#ifndef CHAPTER2_0_SEQUENCELIST_H
#define CHAPTER2_0_SEQUENCELIST_H


/********************************************************************
 *  Project:数据结构第二章
 *  Function:顺序表的抽象数据类型的定义和实现
 *  Description:
 *  Author:左手工匠
 ********************************************************************
 *  Copyright 2019 by 左手工匠
 ********************************************************************/

/**
 * 初始化顺序表
 * @param seqList    要初始化的顺序表
 * @param elemArray  初始化时要添加的元素内容数组
 * @param length     初始化时添加的元素个数
 */
void InitList(SeqList *seqList, ElementType *elemArray, int length);

/**
 * 在顺序表指定的下标插入元素
 * @param seqList    要初始化的顺序表
 * @param index      要插入的下标
 * @param element    要插入的元素
 */
void InsertElement(SeqList *seqList, int index, ElementType element);

/**
 * 删除顺序表中指定下标的元素
 * @param   要操作的顺序表
 * @param   要删除元素的下标
 * @return  返回删除的元素,若删除失败,返回NULL
 */
ElementType *DeleteElement(SeqList *seqList, int index);

/**
 * 返回顺序表中指定下标的元素
 * @param   要操作的顺序表
 * @param   要返回元素的下标
 * @return  返回指定下标的元素,若查找失败,返回NULL
 */
ElementType *GetElement(SeqList *seqList, int index);

/**返回顺序表的长度*/
int GetLength(SeqList *seqList);

/**返回顺序表是否为空*/
int IsEmpty(SeqList *seqList);

/**清空顺序表*/
void ClearList(SeqList *seqList);

/** 打印顺序表*/
void PrintList(SeqList *seqList);

#endif //CHAPTER2_0_SEQUENCELIST_H
