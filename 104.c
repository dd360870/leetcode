#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int maxDepth(struct TreeNode* root) {
    if (root == 0) {
        return 0;
    }
    int dl = maxDepth(root->left);
    int dr = maxDepth(root->right);
    if (dl > dr)
        return dl + 1;
    return dr + 1;
}

int main(void) {
    struct TreeNode* n1 = malloc(sizeof(struct TreeNode));
}