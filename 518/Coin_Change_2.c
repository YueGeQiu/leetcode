// int change(int amount, int* coins, int coinsSize) {
//     int i, j, tmp;

//     int **d = (int **)malloc((coinsSize + 1) * sizeof(int *));
//     if (!d) return 0;

//     for (i = 0; i <= coinsSize; i++) {
//         d[i] = (int *)calloc((amount + 1), sizeof(int));
//         if (!d[i]) return 0;
//         d[i][0] = 1;
//     }

//     for (i = 1; i <= coinsSize; i++) {
//         for (j = 1; j <= amount; j++) {
//             tmp = j >= coins[i-1] ? d[i][j - coins[i-1]] : 0;
//             d[i][j] = d[i-1][j] + tmp;
//         }
//     }

//     tmp = d[coinsSize][amount];

//     for (i = 0; i <= coinsSize; i++) {
//         free(d[i]);
//         d[i] = NULL;
//     }
//     free(d);
//     d = NULL;
//     return tmp;
// }

int change(int amount, int* coins, int coinsSize) {
    int i, j, tmp;

    int *d = (int *)calloc((amount + 1), sizeof(int));
    if (!d) return 0;

    d[0] = 1;

    for (i = 1; i <= coinsSize; i++) {
        for (j = 1; j <= amount; j++) {
            tmp = j >= coins[i-1] ? d[j - coins[i-1]] : 0;
            d[j] += tmp;
        }
    }

    tmp = d[amount];

    free(d);
    d = NULL;

    return tmp;
}
