bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) {
    if (!matrix) return false;

    int left = 0, right = matrixRowSize * matrixColSize - 1, mid;
    int r, c;

    while (left <= right) {
        mid = left + (right - left) / 2;
        r = mid / matrixColSize;
        c = mid % matrixColSize;

        if (target < matrix[r][c]) right = mid - 1;
        else if (target > matrix[r][c]) left = mid + 1;
        else return true;
    }

    return false;
}
