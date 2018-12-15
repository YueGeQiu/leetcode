int minInt(int a, int b) {
    return a > b ? b : a;
}

int minPathSum(int** grid, int gridRowSize, int gridColSize) {
    int *d = (int *)malloc(gridColSize * sizeof(int));
    if (!d) return -1;

    d[0] = grid[0][0];
    int i, j;
    for (j = 1; j < gridColSize; j++) {
        d[j] = d[j - 1] + grid[0][j];
    }

    for (i = 1; i < gridRowSize; i++) {
        d[0] += grid[i][0];
        for (j = 1; j < gridColSize; j++) {
            d[j] = grid[i][j] + minInt(d[j], d[j - 1]);
        }
    }
    return d[gridColSize - 1];
}
