/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int maxTwo(int a, int b) {
    return a > b ? a : b;
}

int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
    if (!nums || numsSize == 0) return NULL;
    *returnSize = numsSize - k + 1;
    int *ret = (int *)malloc(*returnSize * sizeof(int));
    if (!ret) return NULL;

    int *maxFromLeft = (int *)malloc(numsSize * sizeof(int));
    if (!maxFromLeft) return NULL;
    int *maxFromRight = (int *)malloc(numsSize * sizeof(int));
    if (!maxFromRight) return NULL;

    maxFromLeft[0] = nums[0];
    maxFromRight[numsSize-1] = nums[numsSize-1];

    int i, j;
    for (i = 1, j = numsSize - 2; i < numsSize; i++, j--) {
        maxFromLeft[i] = i % k == 0 ? nums[i] : maxTwo(maxFromLeft[i-1], nums[i]);
        maxFromRight[j] = j % k == k - 1 ? nums[j] : maxTwo(maxFromRight[j+1], nums[j]);
    }
    for (i = 0; i < *returnSize; i++) {
        ret[i] = maxTwo(maxFromLeft[i+k-1], maxFromRight[i]);
    }
    free(maxFromLeft);
    free(maxFromRight);
    return ret;
}
