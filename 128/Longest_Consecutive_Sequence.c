int cmp(void *a, void *b) {
    return *(int *)a - *(int *)b;
}

//O(nlog(n))
int longestConsecutive(int* nums, int numsSize) {
    if (!nums || numsSize == 0) return 0;

    qsort(nums, numsSize, sizeof(nums[0]), cmp);

    int i = 0, max = 0, len;

    while (i < numsSize) {
        len = 1;
        while (i < numsSize - 1) {
            if (nums[i+1] - nums[i] > 1) break;
            if (nums[i+1] - nums[i] == 1) len++;
            i++;
        }
        if (len > max) max = len;
        i++;
    }

    return max;
}
