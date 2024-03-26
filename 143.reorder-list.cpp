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
 * @lc app=leetcode id=143 lang=cpp
 *
 * [143] Reorder List
 */

// @lc code=start
class Solution {
public:
    void reorderList(ListNode* head) {
        // Split from middle
        ListNode* slow_prev = NULL,* slow = head, * fast = head;

        while (fast != NULL) {
            slow_prev = slow;
            slow = slow->next;
            fast = fast->next;
            if (fast != NULL) {
                fast = fast->next;
            }
        }
        slow_prev->next = NULL;
        slow = reverseList(slow);

        ListNode* head_next, * slow_next;

        while (slow != NULL && head != NULL) {
            head_next = head->next; 
            slow_next = slow->next;

            head->next = slow;
            slow->next = head_next;

            head = head_next;
            slow = slow_next;
        }
    }

    ListNode* reverseList(ListNode* head) {
        if (head == NULL) {
            return head;
        }
        ListNode* prev = nullptr, * next = head->next;
        while (head != nullptr) {
            head->next = prev;
            prev = head;
            head = next;
            if (next != NULL) {
                next = next->next;
            }
        }
        return prev;
    }
};
// @lc code=end

int main(void) {
    //ListNode n5(5);
    ListNode n4(4);
    ListNode n3(3, &n4);
    ListNode n2(2, &n3);
    ListNode n1(1, &n2);

    Solution s;
    ListNode* res = &n1;
    s.reorderList(&n1);

    while (res != NULL) {
        cout << res->val << endl;
        res = res->next;
    }
}
