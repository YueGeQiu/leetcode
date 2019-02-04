void swap(int *nums, int i, int j) {
    int tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp;
}

int partition(int *nums, int low, int high) {
    int pivot = nums[low], i = low, j = high;
    while (i < j) {
        while (i < j && nums[j] < pivot) j--;
        if (i < j) swap(nums, i, j);
        while (i < j && nums[i] >= pivot) i++;
        if (i < j) swap(nums, i, j);
    }
    return i;
}

int findKthLargest(int* nums, int numsSize, int k) {
    int low = 0, high = numsSize - 1;
    int p;
    while (low <= high) {
        p = partition(nums, low, high);
        if (p == k - 1) return nums[p];
        else if (p < k - 1) low = p + 1;
        else high = p - 1;
    }

    return -1;
}
