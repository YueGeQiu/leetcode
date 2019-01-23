int maxArea(int* height, int heightSize) {
    int max = 0, cur;
    int i = 0, j = heightSize - 1;

    while (i < j) {
        if (height[i] > height[j]) {
            cur = (j - i) * height[j];
            j--;
        } else {
            cur = (j - i) * height[i];
            i++;
        }
        max = max > cur ? max : cur;
    }

    return max;
}
