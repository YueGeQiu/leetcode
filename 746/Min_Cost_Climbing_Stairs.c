int minTwo(int a, int b) {
    return a < b ? a : b;
}

int minCostClimbingStairs(int* cost, int costSize) {
    if (!cost) return 0;
    if (costSize == 1) return cost[0];

    int first = cost[0], second = cost[1];
    int i, cur;

    for (i = 2; i < costSize; i++) {
        cur = cost[i] + minTwo(first, second);
        first = second;
        second = cur;
    }
    return minTwo(first, second);
}
