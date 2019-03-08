#define MAX_INT ((unsigned)(-1)>>1)
#define MIN_INT (~MAX_INT)

#define MIN(a, b) ((a) > (b) ? (b) : (a))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int findUnsortedSubarray(int* nums, int numsSize) {
    if (!nums || numsSize == 0) return 0;
    int i = 0, j = -1, k, p;
    int min = MAX_INT, max = MIN_INT;

    for (k = 0; k < numsSize; k++) {
        max = MAX(nums[k], max);
        if (max != nums[k]) j = k;
        p = numsSize - 1 - k;
        min = MIN(nums[p], min);
        if (min != nums[p]) i = p;
    }
    return j - i + 1;
}
