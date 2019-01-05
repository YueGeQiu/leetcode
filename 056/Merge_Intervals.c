/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 * };
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int cmp(const void *a, const void *b) {
    return ((struct Interval *)a)->start - ((struct Interval *)b)->start;
}
struct Interval* merge(struct Interval* intervals, int intervalsSize, int* returnSize) {
    if (!intervals || intervalsSize == 0) return NULL;

    struct Interval *ret = (struct Interval *)malloc(intervalsSize * sizeof(struct Interval));
    if (!ret) return NULL;

    qsort(intervals, intervalsSize, sizeof(intervals[0]), cmp);

    int i;
    *returnSize = 0;
    for (i = 0; i < intervalsSize; i++) {
        if (*returnSize == 0 || intervals[i].start > ret[*returnSize - 1].end) {
            ret[(*returnSize)++] = intervals[i];
        } else if (intervals[i].end > ret[*returnSize - 1].end) {
            ret[*returnSize - 1].end = intervals[i].end;
        }
    }
    return ret;
}
