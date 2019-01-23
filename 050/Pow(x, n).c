double myPow(double x, int n) {
    double ret = 1;
    long N = n;
    if (n < 0) N = -1l * n;
    while (N != 0) {
        if (N & 1) ret *= x;
        x *= x;
        N >>= 1;
    }
    return n > 0 ? ret : 1/ret;
}
