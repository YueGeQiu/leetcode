/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if (!p && !q) {
        return true;
    }

    if (!p || !q) {
        return false;
    }

    if (p->val != q->val) {
        return false;
    }

    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

bool isSubtree(struct TreeNode* s, struct TreeNode* t) {
    if (!t && !s) {
        return true;
    }

    if (!s) {
        return false;
    }

    return isSameTree(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t);
}
