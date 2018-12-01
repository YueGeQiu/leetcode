/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* deleteNode(struct TreeNode* root, int key) {
    if (!root) return NULL;

    if (root->val < key) root->right = deleteNode(root->right, key);
    else if (root->val > key) root->left = deleteNode(root->left, key);
    else {
        if (root->left == NULL) return root->right;
        if (root->right == NULL) return root->left;

        struct TreeNode *leftMax = root->left;
        while(leftMax->right) leftMax = leftMax->right;

        leftMax->right = root->right;
        root = root->left;
    }
    return root;
}
