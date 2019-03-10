typedef struct {
    int *nums;
    int *origin_nums;
    int size;
} Solution;

Solution* solutionCreate(int* nums, int size) {
    Solution *ret = (Solution *)malloc(sizeof(Solution));
    if (!ret) return NULL;

    ret->nums = (int *)malloc(size * sizeof(int));
    if (!ret->nums) goto fail_nums;

    ret->origin_nums = (int *)malloc(size * sizeof(int));
    if (!ret->origin_nums) goto fail_origin_nums;

    memcpy(ret->nums, nums, sizeof(int) * size);
    memcpy(ret->origin_nums, nums, sizeof(int) * size);
    ret->size = size;
    return ret;

fail_origin_nums:
    free(ret->nums);

fail_nums:
    free(ret);

    return NULL;
}

/** Resets the array to its original configuration and return it. */
int* solutionReset(Solution* obj, int *returnSize) {
    if (!obj || !obj->origin_nums) return NULL;
    *returnSize = obj->size;
    return obj->origin_nums;
}

void swap(int *nums, int a, int b) {
    int tmp = nums[a];
    nums[a] = nums[b];
    nums[b] = tmp;
    return;
}

/** Returns a random shuffling of the array. */
int* solutionShuffle(Solution* obj, int *returnSize) {
    if (!obj || !obj->nums) return NULL;
    *returnSize = obj->size;

    int i, j;
    for (i = obj->size - 1; i > 0; i--) {
        j = random() % (i + 1);
        swap(obj->nums, j, i);
    }
    return obj->nums;
}

void solutionFree(Solution* obj) {
    if (!obj) return;

    if (obj->nums) free(obj->nums);
    if (obj->origin_nums) free(obj->origin_nums);
    free(obj);
    return;
}

/**
 * Your Solution struct will be instantiated and called as such:
 * struct Solution* obj = solutionCreate(nums, size);
 * int* param_1 = solutionReset(obj);
 * int* param_2 = solutionShuffle(obj);
 * solutionFree(obj);
 */