//
// Created by 左手工匠 on 2019/2/3.
//

#include "CircularLinkList.h"

/** 循环链表初始化 */
void InitCircularLinkList(CircularLinkList *clList, ElementType *dataArray, int length) {
    for(int i = 0; i < length; i++) {
        InsertCircularLinkList(clList, i + 1, dataArray[i]);
    }
}

/** 在循环链表的指定位置插入元素 */
void InsertCircularLinkList(CircularLinkList *clList, int pos, ElementType element) {
    CircularNode *node = (CircularNode *)malloc(sizeof(CircularNode));
    //对新创建的结点node进行初始化
    node->next = NULL;
    node->data = element;
    if (pos == 1) {
        node->next = clList->next;
        if (!node->next) {
            //如果长度为0
            node->next = node;
        } else {
            //如果长度不为0,就要找到链表最后一个结点并改变其指针域(即指向node)
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
    //插入的结点不是1的情况
    CircularNode *currNode = clList->next;
    for(int i = 1; currNode && i < pos - 1; i++) {
        currNode = currNode->next;
    }
    if(currNode) {
        node->next = currNode->next;
        currNode->next = node;
        clList->length++;
        //如果插入的位置是最后一个结点
        if(pos == clList->length) {
            node->next = clList->next;
        }
    }
}

void PrintCircularLinkList(CircularLinkList *clList) {
    CircularNode *node = clList->next;
    if(!node->next || clList->length == 0) {
        printf("链表为空,打印失败\n");
        clList->length = 0;
        return;
    }
    for(int i = 0; i < clList->length; i++) {
        printf("%d\t%s\n",node->data.id,node->data.name);
        node = node->next;
    }
}