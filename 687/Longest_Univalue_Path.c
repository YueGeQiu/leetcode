/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int dfs(struct TreeNode* root, int* longestValue) {
    if (!root) {
        return;
    }

    int leftSum = dfs(root->left, longestValue);
    int rightSum = dfs(root->right, longestValue);

    if (root->left && root->val == root->left->val) {
        leftSum += 1;
    } else {
        leftSum = 0;
    }

    if (root->right && root->val == root->right->val) {
        rightSum += 1;
    } else {
        rightSum = 0;
    }

    if (leftSum + rightSum > *longestValue) {
        *longestValue = leftSum + rightSum;
    }

    return leftSum > rightSum ? leftSum : rightSum;
}

int longestUnivaluePath(struct TreeNode* root) {
    int longestValue = 0;

    dfs(root, &longestValue);

    return longestValue;
}
