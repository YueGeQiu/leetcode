/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  struct TreeLinkNode *left, *right, *next;
 * };
 *
 */
struct TreeLinkNode* getNext(struct TreeLinkNode* p{
    while(p) {
        if (p->left) {
            return p->left;
        }
        if (p->right) {
            return p->right;
        }
        p = p->next;
    }
    return NULL;
}

void connect(struct TreeLinkNode *root) {
    if (!root) {
        return;
    }

    if (root->left) {
        if (root->right) {
            root->left->next = root->right;
        } else {
            root->left->next = getNext(root->next);
        }
    }

    if (root->right) {
        root->right->next = getNext(root->next);
    }

    connect(root->right);
    connect(root->left);
    return;
}
