bool isContains(char **wordDict, int wordDictSize, int * wordLen, char *s, int len) {
    int i;
    for (i = 0; i < wordDictSize; i++) {
        if (wordLen[i] == len && strncmp(wordDict[i], s, len) == 0) return true;
    }

    return false;
}

bool wordBreak(char* s, char** wordDict, int wordDictSize) {
    if (!s || !wordDict || !*wordDict || wordDictSize ==0) return false;

    int len = strlen(s);
    int i, j;

    bool *d = (bool *)malloc((len + 1) * sizeof(bool));
    if (!d) return false;
    memset(d, false, (len+1) * sizeof(bool));
    d[0] = true;

    int *wordLen = (int *)malloc(wordDictSize * sizeof(int));
    if (!wordLen) return false;
    for (i = 0; i < wordDictSize; i++) wordLen[i] = strlen(wordDict[i]);

    for (i = 1; i <= len; i++) {
        for (j = i-1; j >= 0; j--) {
            if (d[j] && isContains(wordDict, wordDictSize, wordLen, s+j, i-j)) {
                d[i] = true;
                break;
            }
        }
    }

    bool ret = d[len];
    free(d);
    free(wordLen);

    return ret;
}
