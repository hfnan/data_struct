#include "type.h"
#include "list.h"

// 删除不带头结点的单链表l中所有值为x的结点。
// 时间复杂度 O(n)
// 空间复杂度 O(n)
void delete_x(SLinkList **l, ElemType x) {
    // 由于不带头结点，所以需要在函数内修改指针l的值，故要多加一层引用
    if ((*l) == NULL) return;
    if ((*l)->data == x) {
        SLinkList *p = *l;
        *l = (*l)->next;
        free(p);
        delete_x(l, x);
    } else {
        delete_x(&(*l)->next, x);
    }
}

int main() {
    SLinkList *l = new(SLinkList);
    cons(SLinkList, l, 1, 2, 3, 4, 2, 3, 4, 5, 3, 4, 5, 6);
    dump(SLinkList, l);
    delete_x(&l->next, 3);
    dump(SLinkList, l);        
}