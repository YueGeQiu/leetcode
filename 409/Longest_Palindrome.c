int longestPalindrome(char* s) {
    int d[256] = {0};
    int oddNum = 0, i, unUsed;
    int len = strlen(s);
    while (*s != 0) d[*s++]++;

    for (i = 0; i < 256; i++) {
        if (d[i] % 2 == 1) {
            oddNum++;
        }
    }

    unUsed = oddNum > 0 ? oddNum - 1 : oddNum;
    return len - unUsed;
}
