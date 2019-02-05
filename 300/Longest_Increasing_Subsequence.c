/*
O(n*n)
int lengthOfLIS(int* nums, int numsSize) {
    if (!nums || numsSize == 0) return 0;
    int max = 1, cur, i, j;
    int *d = (int *)calloc(numsSize, sizeof(int));
    if (!d) return 0;

    d[0] = 1;

    for (i = 1; i < numsSize; i++) {
        for (j = 0; j < i; j++) {
            cur = nums[i] > nums[j] ? d[j] + 1 : 1;
            if (cur > d[i]) d[i] = cur;
        }
        if (d[i] > max) max = d[i];
    }
    free(d);
    return max;
}
*/

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

int lengthOfLIS(int* nums, int numsSize) {
    if (!nums || numsSize == 0) return 0;
    int len = 0, index, i;

    int *d = (int *)calloc(numsSize, sizeof(int));
    if (!d) return 0;

    for (i = 0; i < numsSize; i++) {
        index = searchInsert(d, len, nums[i]);
        d[index] = nums[i];
        if (index == len) len++;
    }

    return len;
}
