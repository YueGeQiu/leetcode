/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int treeDepth(struct TreeNode* root) {
    if (!root) {
        return 0;
    }

    int left = treeDepth(root->left);
    int right = treeDepth(root->right);

    return left > right ? left + 1 : right + 1;
}

int absNode(int left, int right) {
    int ret = left - right;
    return ret >= 0 ? ret : 0 - ret;
}

bool isBalanced(struct TreeNode* root) {
    if (!root) {
        return true;
    }

    int left = treeDepth(root->left);
    int right = treeDepth(root->right);

    return (absNode(left, right) <= 1) &&
           isBalanced(root->left) &&
           isBalanced(root->right);
}
