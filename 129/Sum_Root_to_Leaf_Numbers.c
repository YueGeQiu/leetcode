/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void dfs(struct TreeNode* root, int *ret, int sum) {
    sum = sum * 10 + root->val;

    if (!root->left && !root->right) {
        (*ret) += sum;
    } else {
        if (root->left) {
            dfs(root->left, ret, sum);
        }

        if (root->right){
            dfs(root->right, ret, sum);
        }
    }

    return;
}

int sumNumbers(struct TreeNode* root) {
    if (!root) {
        return 0;
    }

    int ret = 0;
    dfs(root, &ret, 0);

    return ret;
}
