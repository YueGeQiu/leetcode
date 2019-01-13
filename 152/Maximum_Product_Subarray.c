int minThree(int a, int b, int c) {
    int d = a < b ? a : b;
    return d < c ? d : c;
}

int maxTwo(int a, int b) {
    return a > b ? a : b;
}

int maxThree(int a, int b, int c) {
    return maxTwo(maxTwo(a, b), c);
}

int maxProduct(int* nums, int numsSize) {
    if (!nums || numsSize == 0) return 0;

    int curMax, curMin, max;
    int a, b, i;

    curMax = curMin = max = nums[0];

    for (i = 1; i < numsSize; i++) {
        a = curMax * nums[i];
        b = curMin * nums[i];
        curMax = maxThree(a, b, nums[i]);
        curMin = minThree(a, b, nums[i]);
        max = maxTwo(curMax, max);
    }
    return max;
}
