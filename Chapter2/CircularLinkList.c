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

/** ɾ��������ָ��λ�õ�Ԫ�� */
ElementType DeleteCircularLinkList(CircularLinkList *clList, int pos) {
    ElementType element;
    element.id = 9999;//��һ�������ܵ�ֵ�����ж�ɾ���Ƿ�ɹ�
    //���ɾ����λ����1
    if(pos == 1) {
        CircularNode *node = clList->next;
        if(node) {
            CircularNode *lastNode = clList->next;
            element = node->data;
            //�ҵ����һ����㲢�ı���ָ�����ָ��
            for(int i = 1; i < clList->length; i++) {
                lastNode = lastNode->next;
            }
            clList->next = node->next;
            lastNode->next = clList->next;
            free(node);
            clList->length--;
        }
        return element;
    }
    //���ɾ����λ�ò�Ϊ1
    CircularNode *preNode;//����һ��ǰ׺���
    CircularNode *node = clList->next;
    for(int i = 1; node && i < pos;i++) {
        preNode = node;
        node = node->next;
    }
    if(node) {
        element = node->data;
        preNode->next = node->next;
        free(node);
        clList->length--;
    }
    return element;
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