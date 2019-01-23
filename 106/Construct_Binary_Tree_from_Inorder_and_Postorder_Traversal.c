/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* buildChildTree(int* inorder, int il, int ir, int* postorder, int pl, int pr){
    if (il > ir) {
        return NULL;
    }

    int i;
    int root_val = postorder[pr];
    int root_in = il - 1;

    for (i = il; i <= ir; i++) {
        if (inorder[i] == root_val) {
            root_in = i;
            break;
        }
    }

    struct TreeNode* root= (struct TreeNode*)calloc(1, sizeof(struct TreeNode));
    if (!root) {
        return NULL;
    }

    int in_left_len = root_in - il;

    root->val = root_val;
    root->left = buildChildTree(inorder, il, root_in -1, postorder, pl, in_left_len + pl - 1);
    root->right = buildChildTree(inorder, root_in + 1, ir, postorder, in_left_len + pl, pr -1);

    return root;
}

struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize) {
    return buildChildTree(inorder, 0, inorderSize - 1, postorder, 0, postorderSize - 1);
}