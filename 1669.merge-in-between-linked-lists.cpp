
#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
 * @lc app=leetcode id=1669 lang=cpp
 *
 * [1669] Merge In Between Linked Lists
 */

// @lc code=start
class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* head = list1;
        int i = 0;
        for (; i < a-1; i++) {
            head = head->next;
        }
        ListNode* start = head;
        for (; i < b; i++) {
            head = head->next;
        }
        ListNode* end = head->next;

        start->next = list2;

        while (list2->next != NULL) list2 = list2->next;

        list2->next = end;

        return list1;
    }
};
// @lc code=end
