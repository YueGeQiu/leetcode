bool isValid(char* s) {
    int len = strlen(s);
    char *stack = (char *)malloc(len * sizeof(char));
    if (!stack) return false;

    int top = -1;

    while (*s != 0) {
        if (*s == '(') stack[++top] = ')';
        else if (*s == '[') stack[++top] = ']';
        else if (*s == '{') stack[++top] = '}';
        else if (top < 0 || stack[top--] != *s) {
            free(stack);
            return false;
        }
        s++;
    }

    free(stack);
    return top == -1;
}
