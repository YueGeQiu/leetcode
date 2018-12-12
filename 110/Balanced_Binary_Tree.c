/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

//return val:
//-1 : not balance
//other : tree depth
int isBalancedBottomUp(struct TreeNode* root) {
    if (!root) return 0;

    int left = isBalancedBottomUp(root->left);
    if (left == -1) return -1;

    int right = isBalancedBottomUp(root->right);
    if (right == -1) return -1;

    if (abs(left - right) > 1) return -1;

    return (left > right ? left : right) + 1;
}

bool isBalanced(struct TreeNode* root) {
    return isBalancedBottomUp(root) != -1;
}
