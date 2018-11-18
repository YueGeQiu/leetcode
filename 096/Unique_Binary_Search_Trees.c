int numTrees(int n) {
    if (n == 0) {
        return 1;
    }
    int i, j;
    int* f = (int*)calloc(n + 1, sizeof(int));
    if (!f) {
        return 0;
    }
    f[0] = 1;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= i; j++) {
            f[i] += f[i - j] * f[j - 1];
        }
    }
    i = f[n];
    free(f);
    f = NULL;
    return i;
}
