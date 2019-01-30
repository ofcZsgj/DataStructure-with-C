#include <stdio.h>
#include <stdlib.h>
#include"DataElement.h"
#include "SequenceList.h"

//��������
ElementType dataArray[] = {
        {1,"Nayuta"},
        {2,"Let it go"},
        {3,"Landscape"},
        {4,"Wings you are the hero"}
};

void TestSequenceList();//����

int main()
{
    TestSequenceList();
    return 0;
}

void TestSequenceList()
{
    //���Գ�ʼ��
    SeqList seqList;    //Ҫ������˳���
    ElementType * delElement;
    InitList(&seqList, dataArray, sizeof(dataArray) / sizeof(dataArray[0]));// 4
    PrintList(&seqList);

    //���Բ���
    InsertElement(&seqList, 4, dataArray[3]);
    printf("�����\n");
    PrintList(&seqList);

    //����ɾ��
    delElement = DeleteElement(&seqList, 1);
    printf("ɾ����\n");
    PrintList(&seqList);
    printf("ɾ����Ԫ��Ϊ\n");
    printf("%d\t%s\n", delElement->id, delElement->name);
    free(delElement);//ʹ����ϼǵ��ͷ��ڴ�(רҵ����!)
}
