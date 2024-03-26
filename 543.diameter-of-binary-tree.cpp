/*
 * @lc app=leetcode id=543 lang=cpp
 *
 * [543] Diameter of Binary Tree
 */

#include <iostream>
#include <queue>
#include <map>
#include <vector>

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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int max_dia = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        visit(root);
        return max_dia;
    }
    int visit(TreeNode *node) {
        if (node == nullptr) {
            return 0;
        }
        int depth_l = visit(node->left);
        int depth_r = visit(node->right);

        if ((depth_l + depth_r) > max_dia) {
            max_dia = (depth_l + depth_r);
        }

        return max(depth_l, depth_r) + 1;
    }
};
// @lc code=end

