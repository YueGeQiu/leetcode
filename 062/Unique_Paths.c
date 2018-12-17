int uniquePaths(int m, int n) {
    if (m < 1 || n < 1) return 0;

    int *d = (int *)malloc(n * sizeof(int));
    if (!d) return 0;

    int i, j, ret;

    for (j = 0; j < n; j++) {
        d[j] = 1;
    }

    for (i = 1; i < m; i++) {
        for (j = 1; j < n; j++) {
            d[j] += d[j-1];
        }
    }

    ret = d[n-1];
    free(d);
    return ret;
}
