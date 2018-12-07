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

// Recursive 
// void dfs(struct TreeNode* root, int* ret, int* tree_index)
// {
//     if (!root) {
//         return;
//     }

//     dfs(root->left, ret, tree_index);

//     ret[(*tree_index)++] = root->val;

//     dfs(root->right, ret, tree_index);
//     return;
// }

// int* inorderTraversal(struct TreeNode* root, int* returnSize) {
//     int* ret = (int *)calloc(1000, sizeof(int));
//     if (!ret) {
//         return NULL;
//     }

//     *returnSize = 0;
//     dfs(root, ret, returnSize);

//     return ret;
// }

// Iterative
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;
    if (!root) {
        return NULL;
    }

    int* ret = (int*)malloc(1000 * sizeof(int));
    if (!ret) {
        return NULL;
    }

    struct TreeNode* stack[1000];
    int top = -1;

    while (root || top >= 0) {
        while (root) {
            stack[++top] = root;
            root = root->left;
        }

        root = stack[top--];
        ret[(*returnSize)++] = root->val;
        root = root->right;
    }

    return ret;
}
