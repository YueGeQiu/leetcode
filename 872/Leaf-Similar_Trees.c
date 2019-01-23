/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void dfs(struct TreeNode* root, int* leaves, int* cur) {
    if (!root) {
        return;
    }

    dfs(root->left, leaves, cur);
    dfs(root->right, leaves, cur);

    if (!root->left && !root->right) {
        leaves[*cur] = root->val;
        (*cur)++;
    }

    return;
}

bool leafSimilar(struct TreeNode* root1, struct TreeNode* root2) {
    int leaves1[100] = {0};
    int leaves2[100] = {0};
    int i, cur1 = 0, cur2 = 0;

    dfs(root1, leaves1, &cur1);
    dfs(root2, leaves2, &cur2);

    if (cur1 != cur2) {
        return false;
    }

    for(i = 0; i < cur1; i++) {
        if (leaves1[i] != leaves2[i]) {
            return false;
        }
    }
    return true;
}
