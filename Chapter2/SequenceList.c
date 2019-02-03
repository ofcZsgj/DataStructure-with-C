//
// Created by 左手工匠 on 2019/1/28.
//

#include"SequenceList.h"
#include"DataElement.h"
#include<stdio.h>
#include<stdlib.h>

/**
 * 初始化顺序表
 * @param seqList    要初始化的顺序表
 * @param elemArray  初始化时要添加的元素内容数组
 * @param length     初始化时添加的元素个数
 */
void InitList(SeqList *seqList, ElementType *elemArray, int length) {
    //初始化顺序表时将顺序表的长度置零!
    seqList->length = 0;
    if (seqList->length > MAX_SIZE) {
        printf("超过了数组最大容量,初始化失败!");
        return;
    }
    //每次循环都在下标为i的位置插入一个元素
    for (int i = 0; i < length; i++) {
        InsertElement(seqList, i, elemArray[i]);
    }
}

/**
 * 在顺序表指定的下标插入元素
 * @param seqList    要初始化的顺序表
 * @param index      要插入的下标
 * @param element    要插入的元素
 */
void InsertElement(SeqList *seqList, int index, ElementType element) {
    //1.验证插入后的元素空间是否超过MAX_SIZE
    //2.index的之是否合法[0,MAX_SIZE-1]
    //3.插入的index应该在length之内
    //4.从第length-1个下标开始,前面一个元素赋值给后面一个元素直到index
    //5.将要插入的值赋给第index个元素
    //6.顺序表的总长度+1!!!!!!!!!!!!!!!!!!!!!!!!
    if (seqList->length + 1 > MAX_SIZE) {
        printf("数组已满,插入元素失败!\n");
        return;
    }
    if (index < 0 || index > MAX_SIZE - 1) {
        printf("只能在允许的下标范围内插入元素[0,%d]\n", MAX_SIZE);
        return;
    }
    if (index > seqList->length) {
        printf("插入的下标超过了数组的最大长度,插入失败\n");
        return;
    }
    //在C89标准中不允许在for循环中直接定义变量,C99方可
    for (int i = seqList->length - 1; i >= index; i--) {
        seqList->datas[i + 1] = seqList->datas[i];
    }
    seqList->datas[index] = element;
    seqList->length++;
}

/**
 * 删除顺序表中指定下标的元素
 * @param   要操作的顺序表
 * @param   要删除元素的下标
 * @return  返回删除的元素,若删除失败,返回NULL
 */
ElementType *DeleteElement(SeqList *seqList, int index) {
    if (index < 0 || index > MAX_SIZE - 1) {
        printf("下标越界,无法删除指定元素\n");
        return NULL;
    }

    //1.找到要删除的元素,保存起来以便返回!!!(保存的是已删除元素的副本)
    //建议使用完毕后进行free,否则会造成内容泄露!!!

    ElementType *delElement = (ElementType *) malloc(sizeof(ElementType));//重点!!!

    //单独定义并调用查找函数,返回要删除元素的指针
    *delElement = *GetElement(seqList, index);

    //2.从指定位置删除,后边一个元素赋值给前面一个元素
    for (int i = index; i < seqList->length - 1; i++) {
        seqList->datas[i] = seqList->datas[i + 1];
    }
    //3.顺序表总长度-1
    seqList->length--;
    return delElement;//建议使用完毕后进行free,否则会造成内存泄露
}

/**
 * 返回顺序表中指定下标的元素
 * @param   要操作的顺序表
 * @param   要返回元素的下标
 * @return  返回指定下标的元素,若查找失败,返回NULL
 */
ElementType *GetElement(SeqList *seqList, int index) {
    if (index < 0 || index > MAX_SIZE - 1) {
        printf("下标越界,无法找到指定元素\n");
        return NULL;
    }
    ElementType *element;//要查找的元素
    element = &seqList->datas[index];
}

/**返回顺序表的长度*/
int GetLength(SeqList *seqList) {
    if (seqList->length == NULL) {
        return 0;
    }
    return seqList->length;
}

/**返回顺序表是否为空*/
int IsEmpty(SeqList *seqList) {
    return GetLength(seqList) == 0 ? TRUE : FALSE;
}

/**清空顺序表*/
void ClearList(SeqList *seqList) {
    if (seqList == NULL) {
        return;
    }
    seqList->length = 0;
}

/**
 * 打印顺序表
 * @param   要操作的顺序表
 */
void PrintList(SeqList *seqList) {
    for (int i = 0; i < seqList->length; i++) {
        printf("%d\t%s\n", seqList->datas[i].id, seqList->datas[i].name);
    }
}

