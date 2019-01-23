/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
char ret[65536];
void dfs(struct TreeNode* t) {
    if (!t) {
        return;
    }

    char tmp[32] = {0};
    sprintf(tmp, "%d", t->val);
    strcat(ret, tmp);

    if (t->left) {
        strcat(ret, "(");
        dfs(t->left);
        strcat(ret, ")");
    }

    if (t->right) {
        if (!t->left) {
            strcat(ret, "()");
        }
        strcat(ret, "(");
        dfs(t->right);
        strcat(ret, ")");
    }

    return;
}
char* tree2str(struct TreeNode* t) {
    memset(ret, 0, 65536);
    dfs(t);
    return ret;
}
