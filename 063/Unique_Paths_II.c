int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridRowSize, int obstacleGridColSize) {
    if (obstacleGridRowSize < 1 || obstacleGridColSize < 1) return 0;

    int *d = (int *)calloc(obstacleGridColSize, sizeof(int));
    if (!d) return 0;

    d[0] = obstacleGrid[0][0] == 1 ? 0 : 1;

    int i, j, ret;
    for (i = 0; i < obstacleGridRowSize; i++) {
        d[0] = obstacleGrid[i][0] == 1 ? 0 : d[0];
        for (j = 1; j < obstacleGridColSize; j++) {
            d[j] = obstacleGrid[i][j] == 1 ? 0 : d[j-1] + d[j];
        }
    }

    ret = d[obstacleGridColSize-1];
    free(d);
    return ret;
}
