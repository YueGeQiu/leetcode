bool isValid(char a, char b) {
    return a == '1' || (a == '2' && b <= '6');
}

int numDecodings(char* s) {
    int len = strlen(s);
    int firtst = 1;
    int second = s[0] == '0' ? 0 : 1;
    int third, i;
    for (i = 1; i < len; i++) {
        third = 0;
        if (s[i] != '0') third += second;
        if (isValid(s[i-1], s[i])) third += firtst;
        firtst = second;
        second = third;
    }
    return second;
}
