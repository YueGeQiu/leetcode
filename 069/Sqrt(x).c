int hammingDistance(int x, int y) {
    int z = x ^ y;
    int ret = 0;
    while(z) {
        ret++;
        z &= (z - 1);
    }
    return ret;
}
