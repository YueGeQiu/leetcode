/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int cmp(void *a, void *b) {
    return *(int *)a - *(int *)b;
}

int** threeSum(int* nums, int numsSize, int* returnSize) {
    int i, j, k, target;

    int **ret = (int **)malloc(numsSize * 6 * sizeof(int *));
    if (!ret) return NULL;
    for (i = 0; i < numsSize * 6; i++) {
        ret[i] = (int *)malloc(3 * sizeof(int));
        if (!ret[i]) return NULL;
    }

    qsort(nums, numsSize, sizeof(nums[0]), cmp);

    *returnSize = 0;
    for (k = numsSize - 1; k >= 2; k--) {
        if (nums[k] < 0) break;
        i = 0;
        j = k - 1;
        target = 0 - nums[k];
        while(i < j) {
            if (nums[i] + nums[j] == target) {
                ret[*returnSize][0] = nums[i];
                ret[*returnSize][1] = nums[j];
                ret[*returnSize][2] = nums[k];
                (*returnSize)++;

                while (i < j && nums[i] == nums[i + 1]) i++;
                while (i < j && nums[j] == nums[j - 1]) j--;

                i++;
                j--;
            } else if (nums[i] + nums[j] < target) {
                i++;
            } else {
                j--;
            }
        }
        while (k >= 2 && nums[k] == nums[k - 1]) k--;
    }
    return ret;
}
