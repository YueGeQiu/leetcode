int maxTwo(int a, int b) {
    return a > b ? a : b;
}

int rob(int* nums, int numsSize) {
    if (!nums) return 0;

    int cur, i;
    int pre1 = 0, pre2 = 0;

    for (i = 0; i < numsSize; i++) {
        cur = maxTwo(pre1, pre2 + nums[i]);
        pre2 = pre1;
        pre1 = cur;
    }
    return pre1;
}
