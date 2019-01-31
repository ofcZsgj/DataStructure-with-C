//
// Created by 左手工匠 on 2019/1/28.
//

#ifndef CHAPTER2_0_DATAELEMENT_H
#define CHAPTER2_0_DATAELEMENT_H

/********************************************************************
 *  Project:数据结构第二章
 *  Function:定义数据元素
 *  Description:
 *  Author:左手工匠
 ********************************************************************
 *  Copyright 2019 by 左手工匠
 ********************************************************************/

#define MAX_SIZE 255

//1.定义数据元素
//typedef int ElementType;
/*
 *datas{{1,""},{2,""},{3,""}};
 */
typedef struct {
    int id;
    char *name;
} ElementType;

//2.定义顺序表结构
typedef struct {
    ElementType datas[MAX_SIZE];//顺序表中的数据元素集合
    int length;                 //当前顺序表中元素个数
} SeqList;

#endif //CHAPTER2_0_DATAELEMENT_H
