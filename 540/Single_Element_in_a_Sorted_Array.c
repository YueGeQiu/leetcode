int singleNonDuplicate(int* nums, int numsSize) {
    int low = 0, high = numsSize - 1;
    int mid;

    while (low <= high) {
        mid = low + (high - low) / 2;
        if (mid + 1 < numsSize && nums[mid] == nums[mid + 1]) {
        } else if (mid - 1 >= low && nums[mid] == nums[mid - 1]) {
            mid--;
        } else {
            return nums[mid];
        }

        if ((mid - low) % 2) high = mid - 1;
        else low = mid + 2;
    }
    return -1;
}
