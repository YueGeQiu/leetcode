int lengthOfLongestSubstring(char* s) {
    int index[256];
    int i, j, maxLen = 0, len = strlen(s);

    for (i = 0; i < 256; i++) index[i] = -1;

    for (i = 0, j = 0; j < len; j++) {
        if (index[s[j]] + 1 > i) i = index[s[j]] + 1;
        if (j - i + 1 > maxLen) maxLen = j - i + 1;
        index[s[j]] = j;
    }
    return maxLen;
}
