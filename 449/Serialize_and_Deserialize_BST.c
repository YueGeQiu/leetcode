/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/** Encodes a tree to a single string. */
#define STR_MAX_LEN 100000

void dfs_ser(struct TreeNode* root, char* ret, int* index) {
    if (!root) {
        return;
    }

    char* tmp = (char*)&root->val;
    ret[(*index)++] = *tmp++;
    ret[(*index)++] = *tmp++;
    ret[(*index)++] = *tmp++;
    ret[(*index)++] = *tmp++;

    char flag = 0;
    if (root->left) {
        flag |= 1;
    }

    if (root->right) {
        flag |= 2;
    }

    ret[(*index)++] = flag;

    dfs_ser(root->left, ret, index);
    dfs_ser(root->right, ret, index);

    return;
}

struct TreeNode* dfs_deser(char* data, int* index) {
    int val;
    char* tmp = (char*)&val;

    *tmp++ = data[(*index)++];
    *tmp++ = data[(*index)++];
    *tmp++ = data[(*index)++];
    *tmp++ = data[(*index)++];

    struct TreeNode* root = (struct TreeNode*)calloc(1, sizeof(struct TreeNode));
    root->val = val;

    char flag = data[(*index)++];
    if (flag & 1) {
        root->left = dfs_deser(data, index);
    }

    if (flag & 2) {
        root->right = dfs_deser(data, index);
    }

    return root;
}

char* serialize(struct TreeNode* root) {
    if (!root) {
        return NULL;
    }

    char* ret = (char*)calloc(STR_MAX_LEN, sizeof(char));
    if (!ret) {
        return NULL;
    }

    int index = 0;
    dfs_ser(root, ret, &index);
    return ret;
}

/** Decodes your encoded data to tree. */
struct TreeNode* deserialize(char* data) {
    if (!data) {
        return NULL;
    }

    int index = 0;
    return dfs_deser(data, &index);
}

// Your functions will be called as such:
// char* data = serialize(root);
// deserialize(data);
