/*
//dp
int countSubstrings(char* s) {
    if (!s) return 0;
    int len = strlen(s);
    if (len == 0) return 0;
    int **d = (int **)malloc(len * sizeof(int *));
    if (!d) return 0;

    int i, j, count = 0;
    for (i = 0; i < len; i++) {
        d[i] = (int *)calloc(len, sizeof(int));
        if (!d[i]) return 0;
    }

    for (i = len - 1; i >= 0; i--) {
        for (j = i; j < len; j++) {
            if (j == i) d[i][j] = 1;
            else if (j == i+1 && s[j] == s[i]) d[i][j] = 1;
            else {
                if (s[j] == s[i]) d[i][j] = d[i+1][j-1];
            }
            if (d[i][j] == 1) count++;
        }
    }

    for (i = 0; i < len; i++) {
        free(d[i]);
    }
    free(d);
    return count;
}
*/

//expand
int expand(char *s, int left, int right) {
    int count = 0, len = strlen(s);
    while (left >= 0 && right < len && s[left] == s[right]) {
        count++;
        left--;
        right++;
    }
    return count;
}

int countSubstrings(char* s) {
    if (!s) return 0;
    int count = 0, len = strlen(s), i;

    for (i = 0; i < len; i++) {
        count += expand(s, i, i);
        count += expand(s, i, i+1);
    }
    return count;
}
