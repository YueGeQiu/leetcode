/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void greater(struct TreeNode* root, int* sum) {
    if (!root) {
        return;
    }

    greater(root->right, sum);
    *sum += root->val;
    root->val = *sum;
    greater(root->left, sum);

    return;
}

struct TreeNode* convertBST(struct TreeNode* root) {
    if (!root) {
        return NULL;
    }

    int sum = 0;
    greater(root, &sum);

    return root;
}
