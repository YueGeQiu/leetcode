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

#define MAX_LEN 1000

/**
 * Recursive
 * 
 * void dfs(struct TreeNode* root, int* ret, int* returnSize) {
 *     if (!root) {
 *         return;
 *     }
 * 
 *     ret[(*returnSize)++] = root->val;
 *     dfs(root->left, ret, returnSize);
 *     dfs(root->right, ret, returnSize);
 *     return;
 * }
 * 
 * int* preorderTraversal(struct TreeNode* root, int* returnSize) {
 *     *returnSize = 0;
 * 
 *     int* ret = (int*)malloc(MAX_LEN * sizeof(int));
 *     if (!ret) {
 *         return NULL;
 *     }
 * 
 *     dfs(root, ret, returnSize);
 *     return ret;
 * }
 */

// Iterative
int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;

    int* ret = (int*)malloc(MAX_LEN * sizeof(int));
    if (!ret) {
        return NULL;
    }

    struct TreeNode* stack[MAX_LEN];
    int top = -1;

    while (root || top >= 0) {
        if (root) {
            ret[(*returnSize)++] = root->val;
            if (root->right) {
                stack[++top] = root->right;
            }
            root = root->left;
        } else {
            root = stack[top--];
        }
    }

    return ret;
}
