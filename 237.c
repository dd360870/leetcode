#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

void deleteNode(struct ListNode* node) {
    struct ListNode* next = node->next;
    node->val   = next->val;
    node->next  = next->next;
    //free(next);
}

int main(void) {
    struct ListNode* i1 = malloc(sizeof(struct ListNode));
    struct ListNode* i2 = malloc(sizeof(struct ListNode));
    struct ListNode* i3 = malloc(sizeof(struct ListNode));
    struct ListNode* i4 = malloc(sizeof(struct ListNode));
    i1->val = 4;
    i1->next = i2;
    i2->val = 5;
    i2->next = i3;
    i3->val = 1;
    i3->next = i4;
    i4->val = 9;
    i4->next = (struct ListNode*) 0;

    struct ListNode* p = i1;

    deleteNode(i2);

    while (p) {
        printf("%d\n", p->val);
        p = p->next;
    }
    free(i1);
    free(i2);
    free(i3);
    free(i4);
}