void swapTwo(int *nums, int left, int right) {
    int tmp = nums[left];
    nums[left] = nums[right];
    nums[right] = tmp;
    return;
}

void sortColors(int* nums, int numsSize) {
    if (!nums) return;
    int left = 0, mid = 0, right = numsSize - 1;

    while (mid <= right) {
        if (nums[mid] == 0) swapTwo(nums, left++, mid++);
        else if (nums[mid] == 1) mid++;
        else swapTwo(nums, mid, right--);
    }

    return;
}
