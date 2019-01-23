int strStr(char* haystack, char* needle) {
    if (!needle) return 0;

    int h = strlen(haystack);
    int n = strlen(needle);

    if (n == 0) return 0;

    int i, j, k;

    for (i = 0; i <= h - n; i++) {
        for (j = i, k = 0; j < h && k < n && haystack[j] == needle[k]; j++, k++);
        if (k == n) return i;
    }

    return -1;
}
