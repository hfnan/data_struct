#include "type.h"
#include "list.h"

// 查找链表中倒数第k个位置上的节点。若查找成功，则输出该节点的data域的值，并返回1；否则只返回0。
// 时间复杂度 O(n)
// 空间复杂度 O(1)
int search_k(SLinkList *list, int k) {
    // 定义两个指针p和q，初始时均指向头结点list的下一个结点（链表的第一个结点）
    SLinkList *p = list->next, *q = list->next;
    int cnt = 0;
    // p指针沿着链表移动，当p指针移动到第k个结点时，q指针开始与p指针同步移动
    // 当p指针移动到最后一个结点时，q指针所指示的结点为倒数第k个结点
    while (p != NULL) {
        if (cnt < k) cnt ++, p = p->next;
        else p = p->next, q = q->next;
    }

    if (cnt < k) return 0; 
    printf("%d\n", q->data);
    return 1;
}

int main(int argc, char **argv) {
    int k = argc == 2? atoi(argv[1]) : 3;
    SLinkList *list = new(SLinkList);
    cons(SLinkList, list, 1, 2, 3, 4, 5, 6, 7, 8);
    dump(SLinkList, list);
    printf("%d\n", search_k(list, k));
    return 0;
}