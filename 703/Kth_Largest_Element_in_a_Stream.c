typedef struct {
    int *nums;
    int size;
    int index;
} KthLargest;

void swap(int *nums, int i, int j) {
    int tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp;
    return;
}

void numsAdd(KthLargest *obj, int val) {
    int *nums = obj->nums;
    int i;

    if (obj->index < obj->size) {
        nums[obj->index] = val;
        for (i = obj->index; i > 0; i--) {
            if (nums[i] < nums[i-1]) swap(nums, i, i - 1);
            else break;
        }
        obj->index++;
    } else if (nums[0] < val) {
        nums[0] = val;
        for (i = 0; i < obj->size - 1; i++) {
            if (nums[i] > nums[i+1]) swap(nums, i, i + 1);
            else break;
        }
    }

    return;
}

// You may assume that nums's length ≥ k-1 and k ≥ 1.
KthLargest* kthLargestCreate(int k, int* nums, int numsSize) {
    KthLargest *ret = (KthLargest *)malloc(sizeof(KthLargest));
    if (!ret) return NULL;

    ret->nums = (int *)malloc(k * sizeof(int));
    if (!ret->nums) return NULL;
    ret->size = k;
    ret->index = 0;

    int i;
    for (i = 0; i < numsSize; i++) {
        numsAdd(ret, nums[i]);
    }

    return ret;
}

int kthLargestAdd(KthLargest* obj, int val) {
    if (!obj || !obj->nums) return -1;

    numsAdd(obj, val);

    return obj->nums[0];
}

void kthLargestFree(KthLargest* obj) {
    if (!obj) return;
    if (obj->nums) free(obj->nums);
    free(obj);
    return;
}

/**
 * Your KthLargest struct will be instantiated and called as such:
 * struct KthLargest* obj = kthLargestCreate(k, nums, numsSize);
 * int param_1 = kthLargestAdd(obj, val);
 * kthLargestFree(obj);
 */