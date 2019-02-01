//
// Created by 左手工匠 on 2019/2/1.
//

#include "LinkList.h"

/** 初始化链表 */
void InitLinkList(LinkList *linkList, ElementType *dataArray, int length) {
    for (int i = 0; i < length; i++) {
        InsertLinkList(linkList, i + 1, dataArray[i]);
    }
}

/** 在指定位置pos处插入元素element */
void InsertLinkList(LinkList *linkList, int pos, ElementType element) {
    //1.创建空结点并为其数据域赋值
    Node *node = (Node *) malloc(sizeof(Node));//创建空结点分配内存
    node->data = element;
    node->next = NULL;
    //如果要插入的位置是1
    if (pos == 1) {
        node->next = linkList->next;
        linkList->next = node;
        linkList->length++;
        return;
    }
    //2.要插入的位置不是1,则通过循环找到要插入结点的位置
    Node *currNode = linkList->next;
    for (int i = 1; currNode && i < pos - 1; i++)//i从1开始!关键(止于pos-1)!
    {
        currNode = currNode->next;
    }
    //3.将结点插入并对接
    if (currNode) {
        node->next = currNode->next;//与后面的元素对接
        currNode->next = node;//与前面的元素对接
        linkList->length++;
    }
}

/** 查询指定位置(pos)的元素 */
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
        printf("链表为空!\n");
        linkList->length = 0;
        return;
    }
    for (int i = 0; i < linkList->length; i++) {
        printf("%d\t%s\n", node->data.id, node->data.name);
        node = node->next;
    }
}
