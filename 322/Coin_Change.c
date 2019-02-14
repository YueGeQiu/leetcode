#define MAX_INT ((unsigned)(-1)>>1)

int coinChange(int* coins, int coinsSize, int amount) {
    if (!coins || coinsSize == 0) return 0;

    int **d = (int **)malloc((coinsSize+1) * sizeof(int *));
    if (!d) return 0;

    int i, j, tmp;
    for (i = 0; i <= coinsSize; i++) {
        d[i] = (int *)calloc(amount+1, sizeof(int));
        if (!d[i]) return 0;
    }

    for (j = 0; j <= amount; j++) {
        d[0][j] = MAX_INT;
    }

    for (i = 1; i <= coinsSize; i++) {
        for (j = 1; j <= amount; j++) {
            tmp = j >= coins[i-1] ? d[i][j-coins[i-1]] : MAX_INT;
            if (tmp != MAX_INT) tmp += 1;
            d[i][j] = tmp < d[i-1][j] ? tmp : d[i-1][j];
        }
    }

    tmp = d[coinsSize][amount] == MAX_INT ? -1 : d[coinsSize][amount];

    for (i = 0; i <= coinsSize; i++) free(d[i]);
    free(d);

    return tmp;
}
