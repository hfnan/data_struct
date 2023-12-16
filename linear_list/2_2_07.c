#include "type.h"
#include "array.h"

// 将两个有序表合并为一个新的有序表。
// 时间复杂度 O(m + n)
// 空间复杂度 O(1)
SqList merge(SqList *a, SqList *b) {
    SqList c;
    c.len = a->len + b->len;
    c.data = (ElemType*)malloc(sizeof(ElemType) * c.len);
    int i, j, k;
    for (i = 0, j = 0, k = 0; i < a->len && j < b->len; ) {
        c.data[k ++ ] = a->data[i] < b->data[j] ? a->data[i ++ ] : b->data[j ++];
    }
    while (i < a->len) c.data[k ++ ] = a->data[i ++ ];
    while (j < b->len) c.data[k ++ ] = b->data[j ++ ];
    return c;
}

int main() {
    SqList a, b;
    cons(a, 1, 3, 5, 7, 9);
    cons(b, 2, 4, 6, 8);
    dump_sqlist(a);
    dump_sqlist(b);
    SqList c = merge(&a, &b);
    dump_sqlist(c);    
}