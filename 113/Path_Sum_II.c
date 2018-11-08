/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

#define MaxLeaves 1000
#define MaxLength 1000

void dfs(struct TreeNode* root, int** ret, int* returnSize, int* int_arr, int sum, int level_len, int* columnSizes) {
    int int_tmp[MaxLength] = {0};
    if (level_len) {
        memcpy(int_tmp, int_arr, level_len * sizeof(int));
    }
    int_tmp[level_len++] = root->val;

    sum -= root->val;

    if (!root->left && !root->right && sum == 0) {
        ret[*returnSize] = (int*)malloc(level_len * sizeof(int));
        memcpy(ret[*returnSize], int_tmp, level_len * sizeof(int));
        columnSizes[*returnSize] = level_len;
        (*returnSize)++;
    } else {
        if (root->left) {
            dfs(root->left, ret, returnSize, int_tmp, sum, level_len, columnSizes);
        }

        if (root->right){
            dfs(root->right, ret, returnSize, int_tmp, sum, level_len, columnSizes);
        }
    }

    return;
}

int** pathSum(struct TreeNode* root, int sum, int** columnSizes, int* returnSize) {
    if (!root) {
        return NULL;
    }

    int **ret = (int**)malloc(MaxLeaves * sizeof(int*));
    if (!ret) {
        return NULL;
    }

    *columnSizes = (int*)malloc(MaxLeaves * sizeof(int));
    if (*columnSizes == NULL) {
        return NULL;
    }

    *returnSize = 0;
    dfs(root, ret, returnSize, NULL, sum, 0, *columnSizes);

    return ret;
}
