#include "type.h"
#include "list.h"

// 找出由s1和s2所指向的两个链表共同后缀的起始位置。
// 时间复杂度 O(m + n)
// 空间复杂度 O(1)
// 比答案更优雅的实现
SLinkList *common_node(SLinkList *s1, SLinkList *s2) {
    SLinkList *p = s1, *q = s2;
    while (1) {
        // 如果p和q指向同一结点，即为所求
        if (p == q) return p;
        // 如果p先移动到了表尾，说明s1比s2短。让p指向长链表的头结点
        // 当q移动到表尾时，p移动到了与短链表头结点对齐的位置，此时让q指向短链表的头结点
        // 此后p与q将并排移动，直到遇到第一个共同后缀结点
        if (p->next == NULL) p = s2;
        if (q->next == NULL) q = s1;
        p = p->next;
        q = q->next;
    }
    // 注：本实现要求必须存在公共后缀，否则会死循环
    // 如果要实现更健壮的程序，可以考虑增加一个计数器，使两个跳转到头结点的操作分别仅执行一次
}

int main() {
    SLinkList *s1 = new(SLinkList), *s2 = new(SLinkList), *t = new(SLinkList);
    cons(SLinkList, s1, 'l', 'o', 'a', 'd');
    cons(SLinkList, s2, 'b', 'e');
    cons(SLinkList, t, 'i', 'n', 'g');
    concat(SLinkList, s1, t);
    concat(SLinkList, s2, t);
    dump(SLinkList, s1);
    dump(SLinkList, s2);
    printf("common_code = %d\n", common_node(s1, s2)->data);
}