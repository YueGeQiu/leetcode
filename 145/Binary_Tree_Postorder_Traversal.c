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
 *     dfs(root->left, ret, returnSize);
 *     dfs(root->right, ret, returnSize);
 *     ret[(*returnSize)++] = root->val;
 *     return;
 * }
 * 
 * int* postorderTraversal(struct TreeNode* root, int* returnSize) {
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
int* postorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;

    if (!root) {
        return NULL;
    }

    int* ret = (int*)malloc(MAX_LEN * sizeof(int));
    if (!ret) {
        return NULL;
    }

    struct TreeNode* stack[MAX_LEN];
    struct TreeNode* pre = NULL;

    int top = -1;

    do {
        while (root && root != pre) {
            stack[++top] = root;
            root = root->left;
        }

        root = stack[top];

        if (!root->right || root->right == pre) {
            ret[(*returnSize)++] = root->val;
            top--;
            pre = root;
        } else {
            root = root->right;
        }
    } while (top >= 0);

    return ret;
}
