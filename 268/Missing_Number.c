int missingNumber(int* nums, int numsSize) {
    int i, ret = numsSize;
    for (i = 0; i < numsSize; i++) {
        ret = ret ^ i ^ nums[i];
    }

    return ret;
}
