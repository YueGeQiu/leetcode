/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* constructFromPrePost(int* pre, int preSize, int* post, int postSize) {
    if (preSize == 0) {
        return NULL;
    }

    struct TreeNode* root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->val = pre[0];

    if (preSize == 1) {
        root->left = root->right = NULL;
        return root;
    }

    int i, left_len;
    for (i = 0; i < postSize; i++) {
        if (post[i] == pre[1]) {
            break;
        }
    }
    left_len = i + 1;

    root->left = constructFromPrePost(pre + 1, left_len, post, left_len);
    root->right = constructFromPrePost(pre + 1 + left_len, preSize - 1 - left_len,
                                        post + left_len, postSize - 1 - left_len);

    return root;
}
