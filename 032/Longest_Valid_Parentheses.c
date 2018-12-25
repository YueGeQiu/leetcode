/*
//d
int longestValidParentheses(char* s) {
    if (!s) return 0;
    int len = strlen(s);
    if (len == 0) return 0;

    int *stack = (int *)calloc(len+1, sizeof(int));
    if (!stack) return 0;

    int max = 0, p = -1, i;
    stack[++p] = -1;

    for (i = 0; i < len; i++) {
        if (stack[p] != -1 && s[stack[p]] == '(' && s[i] == ')') {
            p--;
            if (i - stack[p] > max) max = i - stack[p];
        } else {
            stack[++p] = i;
        }
    }
    free(stack);
    return max;
}
*/

//dp
int longestValidParentheses(char* s) {
    if (!s) return 0;
    int len = strlen(s);
    if (len == 0) return 0;

    int *d = (int *)calloc(len, sizeof(int));
    if (!d) return 0;

    int max = 0, left = 0, i;
    for (i = 0; i < len; i++) {
        if (s[i] == '(') {
            left++;
        } else if (left > 0) {
            d[i] = d[i-1] + 2;
            d[i] += (i - d[i]) >= 0 ? d[i-d[i]] : 0;
            max = d[i] > max ? d[i] : max;
            left--;
        }
    }
    free(d);
    return max;
}
