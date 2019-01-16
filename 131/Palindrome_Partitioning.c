/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void helper(char *s, int len, int start, int **d, char ***ret, int *columnSizes, int *returnSize, char **elem, int index) {
    int end, i;
    if (start >= len) {
        ret[*returnSize] = (char **)malloc(index * sizeof(char *));
        for (i = 0; i < index; i++) {
            ret[*returnSize][i] = (char *)malloc(len * sizeof(char));
            strcpy(ret[*returnSize][i], elem[i]);
        }
        columnSizes[(*returnSize)++] = index;
    } else {
        for (end = start; end < len; end++) {
            if (d[start][end] == 1) {
                memcpy(elem[index], &s[start], end - start + 1);
                elem[index][end - start + 1] = 0;
                helper(s, len, end+1, d, ret, columnSizes, returnSize, elem, index+1);
            }
        }
    }
    return;
}

char*** partition(char* s, int** columnSizes, int* returnSize) {
    if (!s) return NULL;
    int len = strlen(s);
    if (len == 0) return NULL;
    int i, j;

    // int size = pow(2, len-1);
    int size = 200;

    char ***ret = (char ***)malloc(size * sizeof(char **));
    if (!ret) return NULL;

    *columnSizes = (int *)calloc(size, sizeof(int));
    if (!*columnSizes) return NULL;

    int **d = (int **)malloc(len * sizeof(int *));
    if (!d) return NULL;

    int **elem = (int **)malloc(len * sizeof(int *));
    if (!elem) return NULL;

    for (i = 0; i < len; i++) {
        d[i] = (int *)calloc(len, sizeof(int));
        if (!d[i]) return NULL;

        elem[i] = (int *)calloc(len, sizeof(int));
        if (!elem[i]) return NULL;
    }

    for (i = len - 1; i >= 0; i--) {
        for (j = i; j < len; j++) {
            if (j == i) d[i][j] = 1;
            else if (j == i+1 && s[j] == s[i]) d[i][j] = 1;
            else {
                if (s[j] == s[i]) d[i][j] = d[i+1][j-1];
            }
        }
    }

    *returnSize = 0;
    helper(s, len, 0, d, ret, *columnSizes, returnSize, elem, 0);

    for (i = 0; i < len; i++) {
        free(d[i]);
        free(elem[i]);
    }
    free(d);
    free(elem);
    return ret;
}
