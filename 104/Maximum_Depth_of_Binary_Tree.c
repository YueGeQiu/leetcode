/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxDepth(struct TreeNode* root) {
    if (!root) {
        return 0;
    }

    int leftDepth = 0;
    int rightDepth = 0;

    leftDepth = maxDepth(root->left);
    rightDepth = maxDepth(root->right);

    return 1 + (leftDepth > rightDepth ? leftDepth : rightDepth);
}
