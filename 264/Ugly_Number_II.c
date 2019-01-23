int threeMin(int a, int b, int c) {
    if (a < b) {
        return a < c ? a : c;
    } else {
        return b < c ? b : c;
    }
}

int nthUglyNumber(int n) {
    if (n <= 0) return -1;

    int uglyNums[n];
    int i;
    int p2 = 0, p3 = 0, p5 = 0;

    uglyNums[0] = 1;

    for (i = 1; i < n; i++) {
        uglyNums[i] = threeMin(uglyNums[p2] * 2,
                               uglyNums[p3] * 3,
                               uglyNums[p5] * 5);

        if (uglyNums[i] == uglyNums[p2] * 2) p2++;
        if (uglyNums[i] == uglyNums[p3] * 3) p3++;
        if (uglyNums[i] == uglyNums[p5] * 5) p5++;
    }
    return uglyNums[n - 1];
}
