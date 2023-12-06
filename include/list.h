#ifndef DS_LIST_H
#define DS_LIST_H

#include "type.h"

// 构造一个单链表 
// usage: cons(SLinkList, head, 1, 2, 3, 4);
#define cons(ListType, head, ...) do {    \
    ListType *p = head;                   \
    ElemType a[] = {__VA_ARGS__};         \
    int n = sizeof(a) / sizeof(ElemType); \
    for (int i = 0; i < n; i ++) {        \
        ListType *q = new(ListType);      \
        q->data = a[i];                   \
        q->next = p->next;                \
        p->next = q;                      \
        p = q;                            \
    }                                     \
} while (0)

// 输出单链表
#define dump(ListType, head) do {   \
    ListType *p = head->next;       \
    printf("List: ");               \
    while (p) {                     \
        printf("%d ", p->data);     \
        p = p->next;                \
    }                               \
    printf("\n");                   \
} while (0)

// 获得指定链表的尾结点
#define tail(ListType, head, tail) do { \
    tail = head;                        \
    while (tail->next) {                \
        tail = tail->next;              \
    }                                   \
} while (0)

// 连接两个具有头结点的单链表
#define concat(ListType, s1, s2) do { \
    ListType *p;                      \
    tail(ListType, s1, p);            \
    p->next = s2->next;               \
} while (0)

// 单链表
typedef struct SNode {
    ElemType data;
    struct SNode *next;
} SLinkList;

#endif 
