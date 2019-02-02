void swap(char *a, char *b) {
    char tmp = *a;
    *a = *b;
    *b = tmp;
}

char* reverseString(char* s) {
    if (!s) return NULL;

    int start = 0, end = strlen(s) - 1;

    while (start < end) {
        swap(&s[start], &s[end]);
        start++;
        end--;
    }
    return s;
}
