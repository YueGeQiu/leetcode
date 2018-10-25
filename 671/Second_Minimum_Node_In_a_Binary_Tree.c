/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void dfs (struct TreeNode* root, int* min, int* sec_min) {
    if (!root) {
        return;
    }
    
    if (root->val > *min && (*sec_min == -1 || *sec_min > root->val)) {
        *sec_min = root->val;
    }
    dfs(root->left, min, sec_min);
    dfs(root->right, min, sec_min);
    return;
}

int findSecondMinimumValue(struct TreeNode* root) {
    int min = root->val, sec_min = -1;
    dfs(root, &min, &sec_min);
    return sec_min;
}
