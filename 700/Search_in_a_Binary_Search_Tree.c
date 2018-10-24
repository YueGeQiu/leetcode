/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* searchBST(struct TreeNode* root, int val) {
    if (!root) {
        return NULL;
    }
    
    if (root->val == val) {
        return root;
    }
    
    return val < root->val ? searchBST(root->left, val) : searchBST(root->right, val);
}
