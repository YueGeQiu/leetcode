/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void dfs(struct TreeNode* root, int* arr, int* len) {
    if (!root) {
        return;
    }
    dfs(root->left, arr, len);
    arr[*len] = root->val;
    (*len)++;
    dfs(root->right, arr, len);
    return;
}

bool findTarget(struct TreeNode* root, int k) {
    int arr[65535];
    int len = 0, i, j;

    dfs(root, arr, &len);

    for (i = 0, j = len - 1; i <= j; i++) {
        while(j >= i && (arr[i] + arr[j] > k)) {
            j--;
        }
        if (i < j && (arr[i] + arr[j] == k)) {
            return true;
        }
    }

    return false;
}
