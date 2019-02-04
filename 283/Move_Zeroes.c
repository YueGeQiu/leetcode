void swap(int *a, int *b) {
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void moveZeroes(int* nums, int numsSize) {
    if (!nums) return;
    int f = 0, s = 0;

    for (f = 0; f < numsSize; f++) {
        if (nums[f] != 0) {
            swap(&nums[f], &nums[s]);
            s++;
        }
    }
    return;
}
