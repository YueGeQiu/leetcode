/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* constructMaximumBinaryTree(int* nums, int numsSize) {
    int i, max;
    struct TreeNode *head;
    if (numsSize < 1) {
        return NULL;
    }
    for(i = 0, max = 0; i < numsSize; i++) {
        if(nums[i] > nums[max]) {
            max = i;
        }
    }
    head = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    head->val = nums[max];
    head->left = constructMaximumBinaryTree(nums, max);
    head->right = constructMaximumBinaryTree(&nums[max+1], numsSize - (max + 1));
    return head;
}
