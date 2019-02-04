#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"DataElement.h"
#include "SequenceList.h"
#include "LinkList.h"
#include "CircularLinkList.h"

//��������
ElementType dataArray[] = {
        {1, "Nayuta"},
        {2, "Let it go"},
        {3, "Landscape"},
        {4, "Wings you are the hero"}
};

void TestSequenceList();//����˳���

void TestLinkList();//��������

void TestCircularLinkList();//����ѭ������

int main() {
    //TestSequenceList();
    //TestLinkList();
    TestCircularLinkList();
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
    printf("˳���ɾ����Ԫ��Ϊ\n%d\t%s\n", delElement->id, delElement->name);
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

void TestCircularLinkList() {
    //����ѭ�������ʼ��
    CircularLinkList *clList = (CircularLinkList *) malloc(sizeof(CircularLinkList));
    clList->length = 0;
    clList->next = NULL;
    InitCircularLinkList(clList, dataArray, sizeof(dataArray) / sizeof(dataArray[0]));
    printf("ѭ�������ʼ����\n");
    PrintCircularLinkList(clList);

    //����ѭ���������
    InsertCircularLinkList(clList, 1, dataArray[1]);
    printf("ѭ����������\n");
    PrintCircularLinkList(clList);

    //����ѭ������ɾ��
    ElementType delElement = DeleteCircularLinkList(clList, 3);
    printf("ɾ�������Ԫ��Ϊ: %d\t%s\n", delElement.id, delElement.name);
    PrintCircularLinkList(clList);
    printf("ɾ�����ѭ������Ϊ\n");
    PrintCircularLinkList(clList);

    //����ѭ������ı���
    ElementType elem;
    elem.id = 1;
    elem.name = "Nayuta";
    CircularNode *node = GetCircularLinkListNode(clList,elem);
    printf("�ڸ���ѭ������ָ��Ԫ��: %s ��ʼ������ӡΪ\n",elem.name);
    PrintCircularLinkListByNode(clList,node);
}