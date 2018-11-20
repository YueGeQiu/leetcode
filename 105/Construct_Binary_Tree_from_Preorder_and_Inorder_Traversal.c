/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
    if (preorderSize == 0) {
        return NULL;
    }

    struct TreeNode* root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->val = preorder[0];

    if (preorderSize == 1) {
        root->left = root->right = NULL;
        return root;
    }

    int i, left_len;
    for (i = 0; i < inorderSize; i++) {
        if (inorder[i] == root->val) {
            break;
        }
    }
    left_len = i;

    root->left = buildTree(preorder + 1, left_len, inorder, left_len);
    root->right = buildTree(preorder + 1 + left_len, preorderSize - 1 - left_len,
                            inorder + left_len + 1, inorderSize - 1 - left_len);

    return root;
}
