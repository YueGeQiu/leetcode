bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) {
    if (!matrix || !matrix) return false;
    int i = 0, j = matrixColSize - 1;
    while (i < matrixRowSize && j >= 0) {
        if (matrix[i][j] < target) i++;
        else if (matrix[i][j] > target) j--;
        else return true;
    }
    return false;
}
