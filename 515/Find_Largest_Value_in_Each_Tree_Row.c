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

void dfs(struct TreeNode* root, int* ret, int depth, char* flag) {
    if (!root) {
        return;
    }

    if (flag[depth] == 0 || (flag[depth] == 1 && (root->val > ret[depth]))) {
        ret[depth] = root->val;
        flag[depth] = 1;
    }

    dfs(root->left, ret, depth + 1, flag);
    dfs(root->right, ret, depth + 1, flag);
    return;
}

int* largestValues(struct TreeNode* root, int* returnSize) {
    *returnSize = maxDepth(root);
    if (*returnSize == 0) {
        return NULL;
    }

    int* ret = (int*)calloc(*returnSize, sizeof(int));
    if (!ret) {
        return NULL;
    }

    char* flag = (char*)calloc(*returnSize, sizeof(char));
    if (!flag) {
        return NULL;
    }

    dfs(root, ret, 0, flag);
    return ret;
}
