//
// Created by ���ֹ��� on 2019/2/3.
//

#include "CircularLinkList.h"

/** ѭ�������ʼ�� */
void InitCircularLinkList(CircularLinkList *clList, ElementType *dataArray, int length) {
    for(int i = 0; i < length; i++) {
        InsertCircularLinkList(clList, i + 1, dataArray[i]);
    }
}

/** ��ѭ�������ָ��λ�ò���Ԫ�� */
void InsertCircularLinkList(CircularLinkList *clList, int pos, ElementType element) {
    CircularNode *node = (CircularNode *)malloc(sizeof(CircularNode));
    //���´����Ľ��node���г�ʼ��
    node->next = NULL;
    node->data = element;
    if (pos == 1) {
        node->next = clList->next;
        if (!node->next) {
            //�������Ϊ0
            node->next = node;
        } else {
            //������Ȳ�Ϊ0,��Ҫ�ҵ��������һ����㲢�ı���ָ����(��ָ��node)
            CircularNode *lastNode = clList->next;
            for (int i = 1; i < clList->length; i++) {
                lastNode = lastNode->next;
            }
            lastNode->next = node;
        }
        clList->next = node;
        clList->length++;
        return;
    }
    //����Ľ�㲻��1�����
    CircularNode *currNode = clList->next;
    for(int i = 1; currNode && i < pos - 1; i++) {
        currNode = currNode->next;
    }
    if(currNode) {
        node->next = currNode->next;
        currNode->next = node;
        clList->length++;
        //��������λ�������һ�����
        if(pos == clList->length) {
            node->next = clList->next;
        }
    }
}

void PrintCircularLinkList(CircularLinkList *clList) {
    CircularNode *node = clList->next;
    if(!node->next || clList->length == 0) {
        printf("����Ϊ��,��ӡʧ��\n");
        clList->length = 0;
        return;
    }
    for(int i = 0; i < clList->length; i++) {
        printf("%d\t%s\n",node->data.id,node->data.name);
        node = node->next;
    }
}