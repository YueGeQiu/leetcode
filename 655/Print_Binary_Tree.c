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
int maxTwo(int a, int b) {
    return a > b ? a : b;
}

int depth(struct TreeNode *root) {
    if (!root) return 0;

    return 1 + maxTwo(depth(root->left), depth(root->right));
}

void intToChar(char *dst, int a) {
    if (!dst) return;

    sprintf(dst, "%d", a);
    return;
}

void storeTree(struct TreeNode *root, char ***ret, int depth, int start, int end) {
    if (!root || start > end) return;

    int mid = start + (end - start) / 2;

    intToChar(ret[depth][mid], root->val);

    storeTree(root->left, ret, depth+1, start, mid-1);
    storeTree(root->right, ret, depth+1, mid+1, end);
    return;
}

char*** printTree(struct TreeNode* root, int** columnSizes, int* returnSize) {
    *returnSize = depth(root);
    if (*returnSize == 0) return NULL;

    char ***ret = (char ***)malloc(*returnSize * sizeof(char **));
    if (!ret) return NULL;

    int len = pow(2, *returnSize) - 1;

    int i, j;

    for (i = 0; i < *returnSize; i++) {
        ret[i] = (char **)malloc(len * sizeof(char*));
        if (ret[i] == NULL) return NULL;

        for (j = 0; j < len; j++) {
            ret[i][j] = (char *)calloc(5, sizeof(char));
            if (ret[i][j] == NULL) return NULL;
        } 
    }

    *columnSizes = (int *)malloc(len * sizeof(int));
    if (*columnSizes == NULL) return NULL;
    for (i = 0; i < len; i++) columnSizes[0][i] = len;

    storeTree(root, ret, 0, 0, len-1);
    return ret;
}
