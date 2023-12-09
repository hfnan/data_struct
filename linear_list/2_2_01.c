#include "type.h"
#include "array.h"

// 删除顺序表中的最小值，空出的位置用最后一个元素填补。
// 时间复杂度 O(n)
// 空间复杂度 O(1)
ElemType delete_min(SqList *a) {
    ElemType m = a->data[0];
    int j = 0;
    for (int i = 1; i < a->len; i ++) {
        if (a->data[i] < m) {
            j = i;
            m = a->data[i];
        }
    }
    a->data[j] = a->data[a->len - 1];
    a->len --;
    return m;
}

int main() {
    SqList a;
    cons(a, 4, 1, 2, 5, 3);
    dump_sqlist(a);
    delete_min(&a);
    dump_sqlist(a);
}