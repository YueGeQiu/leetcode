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

    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);

    return 1 + (leftDepth > rightDepth ? leftDepth : rightDepth);
}

int diameterOfBinaryTree(struct TreeNode* root) {
    if (!root) {
        return 0;
    }

    int ret = maxDepth(root->left) + maxDepth(root->right);

    int left = diameterOfBinaryTree(root->left);
    int right = diameterOfBinaryTree(root->right);
    int max = left > right ? left : right;

    return ret > max ? ret : max;
}
