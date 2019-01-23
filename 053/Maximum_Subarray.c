#define MAX_INT ((unsigned)(-1)>>1)
#define MIN_INT (~MAX_INT)
int maxSubArray(int* nums, int numsSize) {
    int ret = MIN_INT, tmpSum = 0, i;

    for (i = 0; i < numsSize; i++) {
        tmpSum = tmpSum <= 0 ? nums[i] : (tmpSum + nums[i]);

        if (tmpSum > ret) {
            ret = tmpSum;
        }
    }
    return ret;
}
