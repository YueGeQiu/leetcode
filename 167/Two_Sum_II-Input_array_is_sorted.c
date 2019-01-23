/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    int i = 0, j = numbersSize - 1;
    *returnSize = 2;
    int *ret = (int *)malloc(*returnSize * sizeof(int));
    if (!ret) return NULL;

    ret[0] = ret[1] = -1;
    while (i < j) {
        if (numbers[i] + numbers[j] < target) i++;
        else if (numbers[i] + numbers[j] > target) j--;
        else {
            ret[0] = i + 1;
            ret[1] = j + 1;
            return ret;
        }
    }

    return ret;
}
