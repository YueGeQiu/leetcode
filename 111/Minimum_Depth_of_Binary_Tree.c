/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int minDepth(struct TreeNode* root) {
    if (!root) {
        return 0;
    }

    int leftDepth = 0;
    int rightDepth = 0;

    leftDepth = minDepth(root->left);
    rightDepth = minDepth(root->right);

    return 1 + (leftDepth == 0 || rightDepth == 0 ? leftDepth + rightDepth :
                          (leftDepth > rightDepth ? rightDepth : leftDepth));
}
