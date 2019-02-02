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

/** 删除指定位置的元素并返回该元素的数据 */
ElementType DeleteLinkListElement(LinkList *linkList, int pos) {
    ElementType element;//要删除的元素
    element.id = -9999;//赋一个不可能的值用来判断是否删除成功
    Node *node = NULL;
    //要删除的位置为1的情况
    if(pos == 1) {
        node = linkList->next;
        if(node) {
            element = node->data;
            linkList->next = node->next;
            free(node);//释放被删除结点的内存!
            linkList->length--;
        }
        return element;
    }
    //要删除的位置不是1的情况,需要找到要删除结点以及其前缀结点!
    //主要操作为将前缀(pre)结点->next指向要删除结点->next,即完成删除
    Node *preNode;//定义一个前缀结点
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

/** 清空链表 */
void ClearLinkList(LinkList *linkList) {
    Node *node = linkList->next;
    Node *nextNode;
    while(node) {
        nextNode = node->next;
        free(node);
        node = nextNode;
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
