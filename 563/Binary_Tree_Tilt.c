/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int dfs(struct TreeNode* root, int* res) {
    if (!root) {
        return 0;
    }
    int left = dfs(root->left, res);
    int right = dfs(root->right, res);

    *res += left > right ? left - right : right - left;
    return left + right + root->val;
}

int findTilt(struct TreeNode* root) {
    int res = 0;
    dfs(root, &res);
    return res;
}
