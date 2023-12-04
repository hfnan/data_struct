#ifndef DS_LIST_H
#define DS_LIST_H

#include "type.h"


#define cons(Type, head, ...) do {        \
    Type *p = head;                       \
    int a[] = {__VA_ARGS__};              \
    int n = sizeof(a) / sizeof(ElemType); \
    for (int i = 0; i < n; i ++) {        \
        Type *q = new(Type);              \
        q->data = a[i];                   \
        q->next = p->next;                \
        p->next = q;                      \
        p = q;                            \
    }                                     \
} while (0)

#define dump(Type, head) do {   \
    Type *p = head->next;       \
    printf("List: ");           \
    while (p) {                 \
        printf("%d ", p->data); \
        p = p->next;            \
    }                           \
    printf("\n");               \
} while (0)

// 单链表
typedef struct SNode {
    ElemType data;
    struct SNode *next;
} SLinkList;

#endif 
