#include "type.h"
#include "list.h"

// 删除带头结点的单链表l中所有值为x的结点。
// 时间复杂度 O(n)
// 空间复杂度 O(n) p.s. 如用循环来写，空间复杂度为 O(1)
void delete_x(SLinkList *l, ElemType x) {
    if (l->next == NULL) return ;
    if (l->next->data == x) {
        SLinkList *p = l->next;
        l->next = l->next->next;
        free(p);
        delete_x(l, x);
    } else {
        delete_x(l->next, x);
    }
}

int main() {
    SLinkList *l = new(SLinkList);
    cons(SLinkList, l, 3, 1, 2, 3, 3, 4, 3, 3, 5, 3);
    dump(SLinkList, l);
    delete_x(l, 3);
    dump(SLinkList, l);
}