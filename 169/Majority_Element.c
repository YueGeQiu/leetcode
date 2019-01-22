int majorityElement(int* nums, int numsSize) {
    if (!nums || numsSize == 0) return 0;
    int i, num = nums[0], count = 1;
    for (i = 1; i < numsSize; i++) {
        if (count == 0) {
            num = nums[i];
            count++;
        } else if (num == nums[i]) {
            count++;
        } else {
            count--;
        }
    }
    return num;
}
