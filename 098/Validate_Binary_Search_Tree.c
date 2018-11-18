/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isBST(struct TreeNode* root, int* min, int* max) {
    if (!root) {
        return true;
    }

    if (min && root->val <= *min) {
        return false;
    }

    if (max && root->val >= *max) {
        return false;
    }

    return isBST(root->left, min, &root->val) &&
           isBST(root->right, &root->val, max);
}

bool isValidBST(struct TreeNode* root) {
    return isBST(root, NULL, NULL);
}
