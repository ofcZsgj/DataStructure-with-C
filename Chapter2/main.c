#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"DataElement.h"
#include "SequenceList.h"
#include "LinkList.h"

//��������
ElementType dataArray[] = {
        {1, "Nayuta"},
        {2, "Let it go"},
        {3, "Landscape"},
        {4, "Wings you are the hero"}
};

void TestSequenceList();//����˳���

void TestLinkList();//��������

int main() {
    TestSequenceList();
    TestLinkList();
    return 0;
}

void TestSequenceList() {
    //����˳����ʼ��
    SeqList seqList;    //Ҫ������˳���
    ElementType *delElement;
    InitList(&seqList, dataArray, sizeof(dataArray) / sizeof(dataArray[0]));// 4
    PrintList(&seqList);

    //����˳������
    InsertElement(&seqList, 4, dataArray[3]);
    printf("˳�������\n");
    PrintList(&seqList);

    //����ɾ��
    delElement = DeleteElement(&seqList, 1);
    printf("˳���ɾ����\n");
    PrintList(&seqList);
    printf("˳���ɾ����Ԫ��Ϊ\n");
    printf("%d\t%s\n", delElement->id, delElement->name);
    free(delElement);//ʹ����ϼǵ��ͷ��ڴ�(רҵ����!)
}

void TestLinkList() {
    //���������ʼ��
    LinkList linkList;
    linkList.length = 0;//���׺���
    InitLinkList(&linkList, dataArray, sizeof(dataArray) / sizeof(dataArray[0]));
    PrintLinkList(&linkList);
    //�����������
    ElementType newElement;
    newElement.id = 117;
    newElement.name = (char *) malloc(12);
    stpcpy(newElement.name, "�����������");
    InsertLinkList(&linkList, 3, newElement);
    printf("�������Ԫ�غ�\n");
    PrintLinkList(&linkList);
    //��������ɾ��
    printf("ɾ�����������Ԫ�غ�\n");
    DeleteLinkListElement(&linkList, 3);
    PrintLinkList(&linkList);
    //�����������
    printf("��������\n");
    ClearLinkList(&linkList);
    PrintLinkList(&linkList);
}