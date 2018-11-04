/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
void dfs(struct TreeNode* root, int* ret, int* tree_index)
{
    if (!root) {
        return;
    }

    dfs(root->left, ret, tree_index);

    ret[(*tree_index)++] = root->val;

    dfs(root->right, ret, tree_index);
    return;
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int* ret = (int *)calloc(1000, sizeof(int));
    if (!ret) {
        return NULL;
    }

    *returnSize = 0;
    dfs(root, ret, returnSize);

    return ret;
}
