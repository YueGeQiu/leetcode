int search(int* nums, int numsSize, int target) {
    if (!nums) return -1;

    int left = 0, right = numsSize - 1;
    int mid, i;
    while (left <= right) {
        mid = left + (right - left) / 2;
        if (nums[mid] == target) return mid;
        else if (nums[mid] >= nums[left]) {
            if (target < nums[mid] && target >= nums[left]) right = mid - 1;
            else left = mid + 1;
        } else {
            if (target <= nums[right] && target > nums[mid]) left = mid + 1;
            else right = mid - 1;
        }
    }
    return -1;
}
