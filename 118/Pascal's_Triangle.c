/**
 * Return an array of arrays.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int** columnSizes) {
    int **ret = (int **)malloc(numRows * sizeof(int *));
    if (!ret) return NULL;

    *columnSizes = (int *)malloc(numRows * sizeof(int));
    if (!*columnSizes) return NULL;

    int i, j;
    for (i = 0; i < numRows; i++) {
        (*columnSizes)[i] = i + 1;
        ret[i] = (int *)malloc((*columnSizes)[i] * sizeof(int));
        if (!ret[i]) return NULL;

        ret[i][0] = ret[i][i] = 1;
        for (j = 1; j < i; j++) {
            ret[i][j] = ret[i-1][j-1] + ret[i-1][j];
        }
    }
    return ret;
}
