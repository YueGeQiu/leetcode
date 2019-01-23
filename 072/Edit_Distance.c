int threeMin(int a, int b, int c) {
    int ret;
    if (a > b) ret = b > c ? c : b;
    else ret = a > c ? c : a;

    return ret;
}

int minDistance(char* word1, char* word2) {
    if (word1 == NULL || word2 == NULL) return 0;
    int m = strlen(word1) + 1;
    int n = strlen(word2) + 1;
    int i, j, ret;

    int **d = (int **)malloc(m * sizeof(int*));
    if (!d) return 0;

    for (i = 0; i < m; i++) {
        d[i] = (int *)malloc(n * sizeof(int));
        d[i][0] = i;
    }

    for (j = 0; j < n; j++) {
        d[0][j] = j;
    }

    d[0][0] = 0;

    for (i = 1; i < m; i++) {
        for (j = 1; j < n; j++) {
            if (word1[i-1] == word2[j-1]) d[i][j] = d[i-1][j-1];
            else d[i][j] = threeMin(d[i-1][j], d[i][j-1], d[i-1][j-1]) + 1;
        }
    }

    ret = d[m-1][n-1];

    for (i = 0; i < m; i++) {
        free(d[i]);
        d[i] = NULL;
    }
    free(d);
    d = NULL;

    return ret;
}
