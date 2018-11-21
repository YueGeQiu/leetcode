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
    struct TreeNode* p = root;

    int index = -1;

    while(1) {
        while(p) {
            ret[(*returnSize)++] = p->val;
            if (p->right) {
                stack[++index] = p->right;
            }
            p = p->left;
        }

        if (index == -1) {
            break;
        }

        p = stack[index--];
    }

    return ret;
}
