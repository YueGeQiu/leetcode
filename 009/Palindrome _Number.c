bool isPalindrome(int x) {
    if (x < 0) return false;
    int tmp = x;
    long y = 0;
    while(tmp != 0) {
        y = y * 10 + tmp % 10;
        tmp = tmp / 10;
    }
    return x == y;
}
