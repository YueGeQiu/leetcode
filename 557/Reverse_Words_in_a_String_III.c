char* reverseWords(char* s) {
    if (!s) return NULL;

    int start = 0, end = 0, length = strlen(s);
    int i, j, tmp;

    while (start < length) {
        while (end < length && s[end] != ' ') end++;

        for (i = start, j = end - 1; i < j; i++, j--) {
            tmp = s[i];
            s[i] = s[j];
            s[j] = tmp;
        }
        start = ++end;
    }
    return s;
}
