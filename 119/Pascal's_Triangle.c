/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(int rowIndex, int* returnSize) {
    *returnSize = rowIndex + 1;
    int *ret = (int *)malloc(*returnSize * sizeof(int));
    if (!ret) return NULL;

    int i, j;
    for (i = 0; i <= rowIndex; i++) {
        ret[i] = 1;
        for (j = i - 1; j > 0; j--) {
            ret[j] += ret[j - 1];
        }
    }
    return ret;
}
