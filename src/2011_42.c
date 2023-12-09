#include "type.h"
#include "array.h"

// 找出两个等长升序序列s1和s2的中位数。
// 时间复杂度 O(logn)
// 空间复杂度 O(1)
// 比答案更优雅的实现
ElemType mid(ElemType s1[], ElemType s2[], int n) {
    // i = n / 2 向上取整，j = n / 2  向下取整
    // i表示中位数的位置
    // 通过分析不难得出：序列长度为偶数时，两个中位数中较小者没有可能成为最终的中位数，对于奇数长度序列则不然
    // 故使用j来表示保留后半部分的起始点
    int i = (n + 1) / 2, j = n / 2;
    // m1, m2 是两个序列的中位数
    ElemType m1 = s1[i - 1], m2 = s2[i - 1];
    // 如果序列长度为1，则返回两个数中的较小者
    if (n == 1) 
        return m1 < m2? m1 : m2;
    
    // 如果两个中位数相等，则他们中的一个必然是中位数
    if (m1 == m2) 
        return m1;
    // 如果 m1 < m2，显然小于m1和大于m2的数都不会是中位数，同时，如果是偶数长度序列，则m1也不是中位数
    // 因此对s1的后半部分和s2的前半部分递归地求中位数
    // 显然部分序列的中位数就是原序列的中位数
    else if (m1 < m2) 
        return mid(s1 + j, s2, i);
    // 如果 m1 > m2，情况与上一种是对称的
    else 
        return mid(s1, s2 + j, i);
}

int main () {
    ElemType s1[] = {2, 4, 6, 8, 20}, s2[] = {11, 13, 15, 17, 19};
    dump(s1);
    dump(s2);
    printf("mid = %d\n", mid(s1, s2, 5));
}