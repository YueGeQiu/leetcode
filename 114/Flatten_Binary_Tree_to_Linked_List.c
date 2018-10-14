/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* prev;

void postOrder(struct TreeNode* root) {
    if (!root) {
        return;
    }

    postOrder(root->right);
    postOrder(root->left);
    root->right = prev;
    root->left = NULL;
    prev = root;
    return;
}

void flatten(struct TreeNode* root) {
    prev = NULL;
    return postOrder(root);
}
