#include <stdio.h>
#include <stdlib.h>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* r = calloc(1, sizeof(struct ListNode));
    struct ListNode* curr = r;

    while (l1 || l2) {
        if (!l2 || (l1 && l1->val <= l2->val)) {
            curr->next = l1;
            curr = l1;
            l1 = l1->next;
        }
        else { 
            curr->next = l2;
            curr = l2;
            l2 = l2->next;
        }
    }
    return r->next;
}

int main() {
    struct ListNode* l1;
    struct ListNode* l2;
    struct ListNode* r = mergeTwoLists(l1, l2);

    struct ListNode* pointer = r;

    while (r) {
        printf("%d", r->val);
        r = r->next;
    }
    
}
