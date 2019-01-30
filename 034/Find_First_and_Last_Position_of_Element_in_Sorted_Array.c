/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int* ret = (int*)malloc(2 * sizeof(int));
    if (!ret) {
        return NULL;
    }
    
    ret[0] = ret[1] = -1;
    *returnSize = 2;
    int i = 0;
    for (i = 0; i < numsSize; i++) {
        if (nums[i] == target) {
            if (ret[0] == -1) {
                ret[0] = i;
            }
            ret[1] = i;
        }
    }
    return ret;
}
