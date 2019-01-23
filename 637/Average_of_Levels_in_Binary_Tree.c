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
int maxDepth(struct TreeNode* root) {
    if (!root) {
        return 0;
    }

    int leftDepth = 0;
    int rightDepth = 0;

    leftDepth = maxDepth(root->left);
    rightDepth = maxDepth(root->right);

    return 1 + (leftDepth > rightDepth ? leftDepth : rightDepth);
}

void dfs(struct TreeNode* root, int depth, double* ret, int* width) {
    if (!root) {
        return NULL;
    }

    ret[depth] += root->val;
    width[depth] += 1;
    dfs(root->left, depth + 1, ret, width);
    dfs(root->right, depth + 1, ret, width);
}

double* averageOfLevels(struct TreeNode* root, int* returnSize) {
    if (!root) {
        return NULL;
    }

    *returnSize = maxDepth(root);
    double* ret = (double*)calloc(*returnSize, sizeof(double));
    if (!ret) {
        return NULL;
    }

    int* width = (int*)calloc(*returnSize, sizeof(int));
    if (!width) {
        return NULL;
    }

    dfs(root, 0, ret, width);

    int i;
    for (i = 0; i < *returnSize; i++) {
        ret[i] = ret[i] / width[i];
    }

    free(width);
    return ret;
}
