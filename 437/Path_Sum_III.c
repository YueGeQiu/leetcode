/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int childPathSum(struct TreeNode* root, int sum) {
    if (!root) {
        return 0;
    }

    int val = sum - root->val;
    int ret = 0;

    if (val == 0) {
        ret++;
    }

    return ret + childPathSum(root->left, val) + childPathSum(root->right, val);
}

int pathSum(struct TreeNode* root, int sum) {
    if (!root) {
        return 0;
    }

    int pointSum = childPathSum(root, sum);

    return pointSum + pathSum(root->left, sum) + pathSum(root->right, sum);
}
