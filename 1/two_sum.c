/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
    int i, j, tmp;
    int* result = malloc(2 * sizeof(int));
    if (!result) {
        return NULL;
    }
    for (i = 0; i < numsSize; i++) {
        tmp = target - nums[i];
        for (j = numsSize - 1; j > i; j--) {
            if (nums[j] == tmp) {
                result[0] = i;
                result[1] = j;
                break;
            }
        }
    }
    return result;
}