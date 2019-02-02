//
// Created by ���ֹ��� on 2019/2/1.
//

#include "LinkList.h"

/** ��ʼ������ */
void InitLinkList(LinkList *linkList, ElementType *dataArray, int length) {
    for (int i = 0; i < length; i++) {
        InsertLinkList(linkList, i + 1, dataArray[i]);
    }
}

/** ��ָ��λ��pos������Ԫ��element */
void InsertLinkList(LinkList *linkList, int pos, ElementType element) {
    //1.�����ս�㲢Ϊ��������ֵ
    Node *node = (Node *) malloc(sizeof(Node));//�����ս������ڴ�
    node->data = element;
    node->next = NULL;
    //���Ҫ�����λ����1
    if (pos == 1) {
        node->next = linkList->next;
        linkList->next = node;
        linkList->length++;
        return;
    }
    //2.Ҫ�����λ�ò���1,��ͨ��ѭ���ҵ�Ҫ�������λ��
    Node *currNode = linkList->next;
    for (int i = 1; currNode && i < pos - 1; i++)//i��1��ʼ!�ؼ�(ֹ��pos-1)!
    {
        currNode = currNode->next;
    }
    //3.�������벢�Խ�
    if (currNode) {
        node->next = currNode->next;//������Ԫ�ضԽ�
        currNode->next = node;//��ǰ���Ԫ�ضԽ�
        linkList->length++;
    }
}

/** ɾ��ָ��λ�õ�Ԫ�ز����ظ�Ԫ�ص����� */
ElementType DeleteLinkListElement(LinkList *linkList, int pos) {
    ElementType element;//Ҫɾ����Ԫ��
    element.id = -9999;//��һ�������ܵ�ֵ�����ж��Ƿ�ɾ���ɹ�
    Node *node = NULL;
    //Ҫɾ����λ��Ϊ1�����
    if(pos == 1) {
        node = linkList->next;
        if(node) {
            element = node->data;
            linkList->next = node->next;
            free(node);//�ͷű�ɾ�������ڴ�!
            linkList->length--;
        }
        return element;
    }
    //Ҫɾ����λ�ò���1�����,��Ҫ�ҵ�Ҫɾ������Լ���ǰ׺���!
    //��Ҫ����Ϊ��ǰ׺(pre)���->nextָ��Ҫɾ�����->next,�����ɾ��
    Node *preNode;//����һ��ǰ׺���
    node = linkList->next;
    for(int i = 1; node && i < pos; i++) {
        preNode = node;
        node = node->next;
    }
    if(node) {
        element = node->data;
        preNode->next = node->next;
        free(node);
        linkList->length--;
    }
    return element;
}

/** ������� */
void ClearLinkList(LinkList *linkList) {
    Node *node = linkList->next;
    Node *nextNode;
    while(node) {
        nextNode = node->next;
        free(node);
        node = nextNode;
    }
}

/** ��ѯָ��λ��(pos)��Ԫ�� */
ElementType GetLinkListElement(LinkList * linkList, int pos) {
     Node *node = linkList->next;
     for(int i = 1; node && i < pos; i++) {
         node = node->next;
     }
    return node->data;
}

int IsLinkListEmpty(LinkList *linkList) {
    return linkList->length == 0 ? FALSE : TRUE ;
}

void PrintLinkList(LinkList *linkList) {
    Node *node = linkList->next;
    if (!node) {
        printf("����Ϊ��!\n");
        linkList->length = 0;
        return;
    }
    for (int i = 0; i < linkList->length; i++) {
        printf("%d\t%s\n", node->data.id, node->data.name);
        node = node->next;
    }
}
