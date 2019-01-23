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

#define HASH_MAX 10000

int dfs(struct TreeNode* root, int* hash_val, int* hash_count, int* returnSize, int* count, int* hash_len) {
    if (!root) {
        return 0;
    }

    int sum = dfs(root->left, hash_val, hash_count, returnSize, count, hash_len)
              + dfs(root->right, hash_val, hash_count, returnSize, count, hash_len)
              + root->val;

    int i = 0;

    for (i = 0; i < *hash_len; i++) {
        if (hash_val[i] == sum) {
            hash_count[i]++;
            break;
        }
    }

    if (i == *hash_len) {
        hash_val[i] = sum;
        hash_count[i] = 1;
        (*hash_len)++;
    }

    if (hash_count[i] > *count) {
        *count = hash_count[i];
        *returnSize = 1;
        return sum;
    }

    if (hash_count[i] == *count) {
        (*returnSize)++;
    }

    return sum;
}

int* findFrequentTreeSum(struct TreeNode* root, int* returnSize) {
    int hash_val[HASH_MAX] = {0};
    int hash_count[HASH_MAX] = {0};
    int count = 0, i = 0, j = 0, hash_len = 1;
    *returnSize = 0;

    dfs(root, hash_val, hash_count, returnSize, &count, &hash_len);
    if (*returnSize == 0) {
        return NULL;
    }

    int* ret = (int*)malloc(*returnSize * sizeof(int));
    if (!ret) {
        return NULL;
    }

    for (i = 0; i < hash_len; i++) {
        if (hash_count[i] == count) {
            ret[j++] = hash_val[i];
            if (j >= *returnSize) {
                break;
            }
        }
    }

    return ret;
}
