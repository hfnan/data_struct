#include "type.h"
#include "array.h"

// 有序表中删除重复元素。
// 时间复杂度 O(n)
// 空间复杂度 O(1)
void delete_dup(SqList *a) {
    int j = 1;
    for (int i = 1; i < a->len; i ++ ) {
        if (a->data[i] != a->data[i - 1]) {
            a->data[j ++] = a->data[i];
        }
    }
    a->len = j;
}

int main() {
    SqList a;
    cons(a, 1, 1, 1, 2, 2, 3, 4, 5, 5, 5, 6, 7, 8, 8, 9, 10);
    dump_sqlist(a);
    delete_dup(&a);
    dump_sqlist(a);
}