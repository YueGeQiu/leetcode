void dfs(char **grid, char **visit, int row, int col, int i, int j) {
    if (i < 0 || j < 0 || i >= row || j >= col ||
        grid[i][j] == '0' || visit[i][j] == 1) return;
    
    visit[i][j] = 1;
    dfs(grid, visit, row, col, i - 1, j);
    dfs(grid, visit, row, col, i, j - 1);
    dfs(grid, visit, row, col, i + 1, j);
    dfs(grid, visit, row, col, i, j + 1);
}

int numIslands(char** grid, int gridRowSize, int gridColSize) {
    if (!grid || !grid[0]) return 0;

    char **visit = (char **)malloc(gridRowSize * sizeof(char *));
    if (!visit) return 0;

    int i, j, ret = 0;
    for (i = 0; i < gridRowSize; i++) {
        visit[i] = (char *)calloc(gridColSize, sizeof(char));
        if (!visit[i]) return 0;
    }

    for (i = 0; i < gridRowSize; i++) {
        for (j = 0; j < gridColSize; j++) {
            if (grid[i][j] == '0' || visit[i][j] == 1) continue;
            ret++;
            dfs(grid, visit, gridRowSize, gridColSize, i, j);
        }
    }
    return ret;
}
