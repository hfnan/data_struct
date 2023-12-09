#include "type.h"
#include "array.h"

// 逆置
// 时间复杂度 O(n)
// 空间复杂度 O(1)
void reverse(SqList *a) {
    for (int i = 0, j = a->len - 1; i < j; i ++, j --) {
        ElemType t = a->data[i];
        a->data[i] = a->data[j];
        a->data[j] = t;
    }
}

int main() {
    SqList a;
    cons(a, 1, 2, 3, 4, 5);
    dump_sqlist(a);
    reverse(&a);
    dump_sqlist(a);
}