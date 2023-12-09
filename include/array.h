#ifndef DS_ARRAY_H
#define DS_ARRAY_H

#include "type.h"

#define dump(array) do {                                  \
    int n = sizeof(array) / sizeof(ElemType);             \
    printf("Array: ");                                    \
    for (int i = 0; i < n; i ++) printf("%d ", array[i]); \
    printf("\n");                                         \
} while (0)

#define cons(a, ...) do {                 \
    ElemType t[] = {__VA_ARGS__};         \
    a.len = sizeof(t) / sizeof(ElemType); \
    a.data = newarray(a.len);             \
    for (int i = 0; i < a.len; i ++)      \
        a.data[i] = t[i];                 \
} while(0)

#define dump_sqlist(a) do {          \
    printf("Array: ");               \
    for (int i = 0; i < a.len; i ++) \
        printf("%d ", a.data[i]);    \
    printf("\n");                    \
} while(0)


typedef struct {
    ElemType *data;
    int len;
} SqList;

#endif