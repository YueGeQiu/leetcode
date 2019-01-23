/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

void generate(char **ret, int *returnSize, char *s, int left, int right, int len) {
    if (left == 0 && right == 0) {
        ret[*returnSize] = (char *)malloc(len * sizeof(char));
        strcpy(ret[(*returnSize)++], s);
    } else {
        char tmp[1024] = {0};
        if (left > 0) {
            strcpy(tmp, s);
            strcat(tmp, "(");
            generate(ret, returnSize, tmp, left-1, right, len);
        }
        if (right > left) {
            strcpy(tmp, s);
            strcat(tmp, ")");
            generate(ret, returnSize, tmp, left, right-1, len);
        }
    }
}

char** generateParenthesis(int n, int* returnSize) {
    char **ret = (char **)malloc(5000 * sizeof(char *));
    if (!ret) return NULL;

    *returnSize = 0;
    generate(ret, returnSize, "", n, n, 2 * n);

    return ret;
}
