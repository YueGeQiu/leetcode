/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* childSortedArrayToBST(int* nums, int start, int end) {
    if (start > end) {
        return NULL;
    }

    struct TreeNode* root = calloc(1, sizeof(struct TreeNode));
    if (!root) {
        return NULL;
    }

    int mid = (end - start) / 2 + start;
    root->val = nums[mid];
    root->left = childSortedArrayToBST(nums, start, mid -1);
    root->right = childSortedArrayToBST(nums, mid + 1, end);

    return root;
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    if (numsSize <= 0 || !nums) {
        return NULL;
    }

    return childSortedArrayToBST(nums, 0, numsSize - 1);
}
