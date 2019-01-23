/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void dfs(struct TreeNode* root, int* arr, int* num) {
    if (!root) {
        return;
    }

    dfs(root->left, arr, num);
    arr[(*num)++] = root->val;
    dfs(root->right, arr, num);

    return;
}
struct TreeNode* increasingBST(struct TreeNode* root) {
    int arr[100] = {0};
    int num = 0, i;
    
    dfs(root, arr, &num);
    struct TreeNode* p = NULL;
    struct TreeNode* ret = (struct TreeNode*)calloc(1, sizeof(struct TreeNode));
    if (!ret) {
        return NULL;
    }
    ret->val = arr[0];
    p = ret;
    for (i = 1; i < num; i++) {
        p->right = (struct TreeNode*)calloc(1, sizeof(struct TreeNode));
        if (!p->right) {
            return NULL;
        }
        p->right->val = arr[i];
        p = p->right;
    }

    return ret;
}
