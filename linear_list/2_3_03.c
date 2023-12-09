#include "type.h"
#include "list.h"

void reverse_rec(SLinkList *l) {
    if (l == NULL) return;
    reverse_rec(l->next);
    printf("%d ", l->data);
}

// 时间复杂度 O(n)
// 空间复杂度 O(n) 
void reverse(SLinkList *l) {
    reverse_rec(l->next);
    printf("\n");
}

int main() {
    SLinkList *l = new(SLinkList);
    cons(SLinkList, l, 1, 2, 3, 4, 5);
    dump(SLinkList, l);
    reverse(l);
}