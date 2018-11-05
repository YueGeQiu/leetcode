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
#define MaxLeaves 100
#define MaxLength 1000

void dfs(struct TreeNode* root, char** ret, int* returnSize, char* str) {
    char str_tmp[MaxLength] = {0};
    if (!str) {
        sprintf(str_tmp, "%d", root->val);
    } else {
        sprintf(str_tmp, "%s->%d", str, root->val);
    }

    if (!root->left && !root->right) {
        strcpy(ret[(*returnSize)++], str_tmp);
    } else {
        if (root->left) {
            dfs(root->left, ret, returnSize, str_tmp);
        }

        if (root->right){
            dfs(root->right, ret, returnSize, str_tmp);
        }
    }

    return;
}

char** binaryTreePaths(struct TreeNode* root, int* returnSize) {
    if (!root) {
        return NULL;
    }

    char **ret = (char**)malloc(MaxLeaves * sizeof(char*));
    if (!ret) {
        return NULL;
    }

    int i;
    for (i = 0; i < MaxLeaves; i++) {
        ret[i] = (char*)calloc(MaxLength, sizeof(char));
        if (!ret[i]) {
            return NULL;
        }
    }

    *returnSize = 0;
    dfs(root, ret, returnSize, NULL);

    return ret;
}