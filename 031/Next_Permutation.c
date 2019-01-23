void swap(int *nums, int i, int j) {
    int tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp;
    return;
}

void nextPermutation(int* nums, int numsSize) {
    if (!nums || numsSize < 2) return;
    int i, j, p;
    p = numsSize - 2;
    while (p >= 0 && nums[p] >= nums[p+1]) p--;

    if (p >= 0 ) {
        i = numsSize - 1;
        while (nums[i] <= nums[p]) i--;
        swap(nums, i, p);
    }

    for (i = p + 1, j = numsSize - 1; i < j; i++, j--) {
        swap(nums, i, j);
    }
    return;
}
