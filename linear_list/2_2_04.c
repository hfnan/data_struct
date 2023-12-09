#include "type.h"
#include "array.h"

// 删除值在l与r之间的所有元素。
// 时间复杂度 O(n)
// 空间复杂度 O(1)
void delete_l_r(SqList *a, ElemType l, ElemType r) {
    int j = 0;
    for (int i = 0; i < a->len; i ++) {
        if (a->data[i] < l || a->data[i] > r) {
            a->data[j ++] = a->data[i];        
        }
    }
    a->len = j;
}

int main() {
    SqList a;
    cons(a, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
    dump_sqlist(a);
    delete_l_r(&a, 3, 7);
    dump_sqlist(a);
}