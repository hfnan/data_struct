#include "type.h"
#include "array.h"

// 删除线性表中所有值为x的数据元素。
// 时间复杂度 O(n)
// 空间复杂度 O(1)
void delete_x(SqList *a, ElemType x) {
    int j = 0;
    for (int i = 0; i < a->len; i ++) {
        if (a->data[i] != x) {
            a->data[j ++] = a->data[i];        
        }
    }
    a->len = j;
}

int main() {
    SqList a;
    cons(a, 3, 2, 1, 3, 2, 1, 2, 3);
    dump_sqlist(a);
    delete_x(&a, 3);
    dump_sqlist(a);
}