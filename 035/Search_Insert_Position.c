int searchInsert(int* nums, int numsSize, int target) {
    if (!nums) return -1;

    int left = 0, right = numsSize - 1, mid;

    while(left <= right) {
        mid = left + (right - left) / 2;
        if (target > nums[mid]) left = mid + 1;
        else if (target < nums[mid]) right = mid - 1;
        else return mid;
    }

    return left;
}
