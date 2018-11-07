/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* mergeTrees(struct TreeNode* t1, struct TreeNode* t2) {
    if(!t1 && !t2) {
        return NULL;
    }
    struct TreeNode *pHead = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    pHead->val = (t1?t1->val:0) + (t2?t2->val:0);
    pHead->left = mergeTrees(t1?t1->left:NULL, t2?t2->left:NULL);
    pHead->right = mergeTrees(t1?t1->right:NULL, t2?t2->right:NULL);
    return pHead;
}
