int singleNumber(int* nums, int numsSize) {
    int ret = 0, i = 0;
    for (i; i < numsSize; i++) ret ^= nums[i];
    return ret;
}