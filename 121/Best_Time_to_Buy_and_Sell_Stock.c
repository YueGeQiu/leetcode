int maxProfit(int* prices, int pricesSize) {
    if (pricesSize < 2) return 0;
    int max = 0, buy = prices[0], i;

    for (i = 1; i < pricesSize; i++) {
        if (prices[i] < buy) buy = prices[i];
        else if (prices[i] - buy > max) max = prices[i] - buy;
    }
    return max;
}
