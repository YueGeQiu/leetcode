int palindromeLength(char *s, int left, int right) {
    int len = strlen(s);
    while(left >= 0 && right < len && s[left] == s[right]) {
        left--;
        right++;
    }

    // (right - 1) - (left + 1) + 1
    return right - left - 1;
}

char* longestPalindrome(char* s) {
    if (!s) return NULL;

    int start = 0, Maxlen = 0;
    int len1, len2, len, i;
    int str_len = strlen(s);
    char *ret = (char *)malloc(1001 * sizeof(char));
    if (!ret) return NULL;

    for (i = 0; i < str_len; i++) {
        len1 = palindromeLength(s, i, i);
        len2 = palindromeLength(s, i, i+1);

        len = len1 > len2 ? len1 : len2;
        if (len > Maxlen) {
            Maxlen = len;
            start = i - (len - 1)/2;
        }
    }

    strncpy(ret, s+start, Maxlen);
    ret[Maxlen] = 0;
    return ret;
}
