int maxTwo(int a, int b) {
    return a > b ? a : b;
}

int robLength(int* nums, int start, int end) {
    int cur, i;
    int pre1 = 0, pre2 = 0;

    for (i = start; i <= end; i++) {
        cur = maxTwo(pre1, pre2 + nums[i]);
        pre2 = pre1;
        pre1 = cur;
    }
    return pre1;
}

int rob(int* nums, int numsSize) {
    if (!nums) return 0;
    if (numsSize == 1) return nums[0];

    return maxTwo(robLength(nums, 0, numsSize - 2),
                  robLength(nums, 1, numsSize - 1));
}
