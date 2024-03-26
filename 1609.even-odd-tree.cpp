/*
 * @lc app=leetcode id=1609 lang=cpp
 *
 * [1609] Even Odd Tree
 */

#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// @lc code=start
class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;   
        q.push(root);

        int level = 0;

        while (!q.empty()) {

            int size = q.size();

            // pop first element
            TreeNode *prev = nullptr;

            for (; size > 0; size--) {
                TreeNode *node = q.front();
                q.pop();
                if (node->left != nullptr) q.push(node->left);
                if (node->right != nullptr) q.push(node->right);
                if (level % 2 == 0 && !(node->val % 2 == 1 && (prev == nullptr || node->val > prev->val))) {
                    return false;
                }
                if (level % 2 == 1 && !(node->val % 2 == 0 && (prev == nullptr || node->val < prev->val))) {
                    return false;
                }
                prev = node;
            }
            level++;
        }

        return true;
    }
};
// @lc code=end

