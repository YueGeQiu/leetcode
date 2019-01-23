/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isSymmetricTree(struct TreeNode* p, struct TreeNode* q) {
    if (p && q) {
        return p->val == q->val && 
               isSymmetricTree(p->left, q->right) &&
               isSymmetricTree(p->right, q->left);
    } else {
        return p == NULL && q == NULL;
    }
}

bool isSymmetric(struct TreeNode* root) {
    if (!root) return true;

    return isSymmetricTree(root->left, root->right);
}
