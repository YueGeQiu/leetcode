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

int maxDepth(struct TreeNode* root) {
    if (!root) {
        return 0;
    }

    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);

    return 1 + (leftDepth > rightDepth ? leftDepth : rightDepth);
}

void everyLevel(struct TreeNode* root, int* arr) {
    if (!root) {
        return;
    }

    arr[0]++;
    everyLevel(root->left, arr + 1);
    everyLevel(root->right, arr + 1);

    return;
}

void everyLevelSet(struct TreeNode* root, int** arr, int* tmp, int depth) {
    if (!root) {
        return;
    }

    arr[depth][tmp[depth]] = root->val;
    tmp[depth]++;

    everyLevelSet(root->left, arr, tmp, depth + 1);
    everyLevelSet(root->right, arr, tmp, depth + 1);

    return;
}

int** levelOrder(struct TreeNode* root, int** columnSizes, int* returnSize) {
    if (!root) {
        *columnSizes = NULL;
        *returnSize = 0;
        return NULL;
    }

    *returnSize = maxDepth(root);

    int *tmp_column = (int *)calloc(*returnSize, sizeof(int));
    if (!tmp_column) {
        *columnSizes = NULL;
        *returnSize = 0;
        return NULL;
    }

    everyLevel(root, tmp_column);

    int **ret = (int **)calloc(*returnSize, sizeof(int *));
    if (!ret) {
        *columnSizes = NULL;
        *returnSize = 0;
        return NULL;
    }

    int i;
    for (i = 0; i < *returnSize; i++) {
        ret[i] = (int *)calloc(tmp_column[i], sizeof(int));
        if (!ret[i]) {
            *columnSizes = NULL;
            *returnSize = 0;
            return NULL;
        }
    }

    int *tmp = (int *)calloc(*returnSize, sizeof(int));
    if (!tmp) {
        *columnSizes = NULL;
        *returnSize = 0;
        return NULL;
    }
    everyLevelSet(root, ret, tmp, 0);
    free(tmp);

    *columnSizes = tmp_column;
    return ret;
}
