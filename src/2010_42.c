#include "type.h"
#include "array.h"

// 将长度为len的数组R翻转。
// 时间复杂度 O(n)
// 空间复杂度 O(1)
void reverse(int len, ElemType R[]) {
    for (int i = 0, j = len - 1; i < j; i ++, j --) {
        ElemType t = R[i];
        R[i] = R[j];
        R[j] = t;
    }
}

// 将R中保存的序列循环左移p个位置。
// 时间复杂度 O(n)
// 空间复杂度 O(1)
void rec_left_shift(int n, int p, ElemType R[]) {
    // ab -> ba
    // a -> a^(-1)
    reverse(p, R);
    // b -> b^(-1)
    reverse(n - p, R + p);
    // a^(-1)b^(-1) -> (a^(-1)b^(-1))^(-1) = ba
    reverse(n, R);   
}

int main() {
    ElemType R[] = {1, 2, 3, 4, 5, 6, 7, 8};
    dump(ElemType, R);
    rec_left_shift(8, 4, R);
    dump(ElemType, R);
}