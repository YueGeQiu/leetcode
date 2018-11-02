/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void swap(struct TreeNode** left, struct TreeNode** right) {
    struct TreeNode* tmp;
    tmp = *left;
    *left = *right;
    *right = tmp;
}

void dfs(struct TreeNode* root) {
    if(!root) {
        return;
    }

    swap(&root->left, &root->right);

    dfs(root->left);
    dfs(root->right);
}

struct TreeNode* invertTree(struct TreeNode* root) {
    dfs(root);
    return root;
}
