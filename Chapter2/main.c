#include <stdio.h>
#include <stdlib.h>
#include"DataElement.h"
#include "SequenceList.h"

//测试数据
ElementType dataArray[] = {
        {1, "Nayuta"},
        {2, "Let it go"},
        {3, "Landscape"},
        {4, "Wings you are the hero"}
};

void TestSequenceList();//测试

int main() {
    TestSequenceList();
    return 0;
}

void TestSequenceList() {
    //测试初始化
    SeqList seqList;    //要操作的顺序表
    ElementType *delElement;
    InitList(&seqList, dataArray, sizeof(dataArray) / sizeof(dataArray[0]));// 4
    PrintList(&seqList);

    //测试插入
    InsertElement(&seqList, 4, dataArray[3]);
    printf("插入后\n");
    PrintList(&seqList);

    //测试删除
    delElement = DeleteElement(&seqList, 1);
    printf("删除后\n");
    PrintList(&seqList);
    printf("删除的元素为\n");
    printf("%d\t%s\n", delElement->id, delElement->name);
    free(delElement);//使用完毕记得释放内存(专业做法!)
}
