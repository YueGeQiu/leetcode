/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int factorial(int n) {
    int ret = 1, i;
    for (i = 1; i <= n; i++) ret *= i;

    return ret;
}

void swap(int *nums, int a, int b) {
    int tmp = nums[a];
    nums[a] = nums[b];
    nums[b] = tmp;
    return;
}

void permuteRec(int *nums, int numsSize, int start, int **ret, int *count) {
    if (start == numsSize) {
        ret[*count] = (int *)malloc(numsSize * sizeof(int));
        memcpy(ret[*count], nums, numsSize * sizeof(int));
        (*count)++;
    } else {
        int i;
        for (i = start; i < numsSize; i++) {
            swap(nums, i, start);
            permuteRec(nums, numsSize, start+1, ret, count);
            swap(nums, i, start);
        }
    }
    return;
}

int** permute(int* nums, int numsSize, int* returnSize) {
    if (!nums || numsSize <= 0) return NULL;
    int **ret = (int **)malloc(factorial(numsSize) * sizeof(int *));
    if (!ret) return NULL;

    *returnSize = 0;
    permuteRec(nums, numsSize, 0, ret, returnSize);
    return ret;
}