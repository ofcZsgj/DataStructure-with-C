#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"DataElement.h"
#include "SequenceList.h"
#include "LinkList.h"
#include "CircularLinkList.h"

//测试数据
ElementType dataArray[] = {
        {1, "Nayuta"},
        {2, "Let it go"},
        {3, "Landscape"},
        {4, "Wings you are the hero"}
};

void TestSequenceList();//测试顺序表

void TestLinkList();//测试链表

void TestCircularLinkList();//测试循环链表

int main() {
    //TestSequenceList();
    //TestLinkList();
    TestCircularLinkList();
    return 0;
}

void TestSequenceList() {
    //测试顺序表初始化
    SeqList seqList;    //要操作的顺序表
    ElementType *delElement;
    InitList(&seqList, dataArray, sizeof(dataArray) / sizeof(dataArray[0]));// 4
    PrintList(&seqList);

    //测试顺序表插入
    InsertElement(&seqList, 4, dataArray[3]);
    printf("顺序表插入后\n");
    PrintList(&seqList);

    //测试删除
    delElement = DeleteElement(&seqList, 1);
    printf("顺序表删除后\n");
    PrintList(&seqList);
    printf("顺序表删除的元素为\n%d\t%s\n", delElement->id, delElement->name);
    free(delElement);//使用完毕记得释放内存(专业做法!)
}

void TestLinkList() {
    //测试链表初始化
    LinkList linkList;
    linkList.length = 0;//容易忽略
    InitLinkList(&linkList, dataArray, sizeof(dataArray) / sizeof(dataArray[0]));
    PrintLinkList(&linkList);

    //测试链表插入
    ElementType newElement;
    newElement.id = 117;
    newElement.name = (char *) malloc(12);
    stpcpy(newElement.name, "测试链表插入");
    InsertLinkList(&linkList, 3, newElement);
    printf("链表插入元素后\n");
    PrintLinkList(&linkList);
    //测试链表删除

    printf("删除链表第三个元素后\n");
    DeleteLinkListElement(&linkList, 3);
    PrintLinkList(&linkList);
    //测试清空链表

    printf("清空链表后\n");
    ClearLinkList(&linkList);
    PrintLinkList(&linkList);
}

void TestCircularLinkList() {
    //测试循环链表初始化
    CircularLinkList *clList = (CircularLinkList *)malloc(sizeof(CircularLinkList));
    clList->length = 0;
    clList->next = NULL;
    InitCircularLinkList(clList, dataArray, sizeof(dataArray) / sizeof(dataArray[0]));
    printf("循环链表初始化后\n");
    PrintCircularLinkList(clList);

    //测试循环链表插入
    InsertCircularLinkList(clList, 1, dataArray[1]);
    printf("循环链表插入后\n");
    PrintCircularLinkList(clList);

    //测试循环链表删除
    ElementType delElement = DeleteCircularLinkList(clList, 3);
    printf("删除链表的元素为: %d\t%s\n",delElement.id,delElement.name);
    PrintCircularLinkList(clList);
    printf("删除后的循环链表为\n");
    PrintCircularLinkList(clList);
}