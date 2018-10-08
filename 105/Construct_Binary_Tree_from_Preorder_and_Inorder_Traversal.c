/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* buildChildTree(int* preorder, int pl, int pr, int* inorder, int il, int ir) {
    if (il > ir) {
        return NULL;
    }

    int i, left_len;

    struct TreeNode* root = (struct TreeNode *)calloc(1, sizeof(struct TreeNode));
    if (!root) {
        return NULL;
    }
    root->val = preorder[pl];

    for (i = il; i <= ir; i++) {
        if (inorder[i] == root->val) {
            break;
        }
    }
    left_len = i - il;

    root->left = buildChildTree(preorder, pl + 1, pl + left_len, inorder, il, i - 1);
    root->right = buildChildTree(preorder, pl + left_len + 1, pr, inorder, i + 1, ir);

    return root;
}

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
    return buildChildTree(preorder, 0, preorderSize - 1, inorder, 0, inorderSize - 1);
}