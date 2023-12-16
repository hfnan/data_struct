#include "type.h"
#include "array.h"

// 在有序表中查找值为x的元素。若找到，则与其后继元素交换；否则，将其插入表中并保持表有序。
// 时间复杂度 O(m + n)
// 空间复杂度 O(1)
void half_search(SqList *a, ElemType x) {
    int l = 0, r = a->len - 1, mid;
    while(l <= r) {
        mid = (l + r) / 2;
        if (x == a->data[mid]) break;
        else if (a->data[mid] > x) r = mid - 1;
        else l = mid + 1;
    }

    if (x == a->data[mid] && mid != a->len - 1) {
        a->data[mid] = a->data[mid + 1];
        a->data[mid + 1] = x;
    }
    if (l > r) {
        a->len ++;
        a->data = (ElemType*)realloc(a->data, sizeof(ElemType) * a->len);
        for (int i = a->len - 1; i > r + 1; i -- ) 
            a->data[i] = a->data[i - 1];
        a->data[r + 1] = x;
    }
}   

int main() {
    SqList a;
    cons(a, 1, 3, 5, 7, 9);
    dump_sqlist(a);
    half_search(&a, 0);
    dump_sqlist(a);
}