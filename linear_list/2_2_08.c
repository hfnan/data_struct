#include "type.h"
#include "array.h"

void reverse(ElemType a[], int n) {
    for (int i = 0, j = n - 1; i < j; i ++, j --) {
        ElemType t = a[i];
        a[i] = a[j];
        a[j] = t;
    }
}

// 将数组中两个顺序表的位置互换。
// 时间复杂度 O(m + n)
// 空间复杂度 O(1)
void swap(ElemType a[], int m, int n) {
    // [A B] -> [B A]
    reverse(a, m + n);
    reverse(a, n);
    reverse(a + n, m);
}

int main() {
    ElemType a[] = {1, 3, 5, 7, 9, 2, 4, 6, 8};
    dump(a);
    swap(a, 5, 4);
    dump(a);
}