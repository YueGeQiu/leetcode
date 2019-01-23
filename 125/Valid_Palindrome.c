bool isAlphanumeric(char a) {
    return (a <= 'Z' && a >= 'A') || (a <= 'z' && a >= 'a')
        || (a <= '9' && a >= '0');
}

bool isEqulIgnoreCase(char a, char b) {
    if (a <= 'Z' && a >= 'A') a += 32;
    if (b <= 'Z' && b >= 'A') b += 32;
    return a == b;
}

bool isPalindrome(char* s) {
    if (!s) return true;
    int i = 0, j = strlen(s) - 1;
    if (j <= 0) return true;
    while(i < j) {
        while(i < j && !isAlphanumeric(s[i])) i++;
        while(i < j && !isAlphanumeric(s[j])) j--;
        if(i < j && !isEqulIgnoreCase(s[i], s[j])) return false;
        i++;
        j--;
    }
    return true;
}