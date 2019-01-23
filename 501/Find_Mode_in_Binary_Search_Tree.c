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

#define INIT_RET_SIZE 10000
int g_number, g_sum, g_flag, g_retsize;

void check(int* ret) {
    if (g_sum > g_flag) {
        g_flag = g_sum;
        memset(ret, 0, INIT_RET_SIZE);
        g_retsize = 0;
    } 
    if (g_sum == g_flag) {
        ret[g_retsize++] = g_number;
    }
}

void dfs(struct TreeNode* root, int* ret) {
    if (!root) {
        return;
    }
    
    dfs(root->left, ret);
    if (root->val == g_number) {
        g_sum++;
    } else {
        check(ret);
        g_number = root->val;
        g_sum = 1;
    }
    dfs(root->right, ret);
}

int* findMode(struct TreeNode* root, int* returnSize) {
    if (!root) {
        return NULL;
    }

    g_number = 1 << 31;
    g_sum = 0;
    g_flag = 0;
    g_retsize = 0;

    int* ret = (int *)calloc(INIT_RET_SIZE, sizeof(int));
    if (!ret) {
        return NULL;
    }
    
    dfs(root, ret);
    check(ret);
    *returnSize = g_retsize;
    return ret;
}
