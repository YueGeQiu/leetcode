/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool hasPathSum(struct TreeNode* root, int sum) {
    if (!root) {
        return false;
    }
    
    int val = sum - root->val;
    
    if (val == 0 && !root->left && !root->right) {
        return true;
    }
    
    return hasPathSum(root->left, val) || hasPathSum(root->right, val);
}
