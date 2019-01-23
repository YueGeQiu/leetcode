// recursive
// int climbStairs(int n) {
//     if (n < 2) return 1;
//     return climbStairs(n - 1) + climbStairs(n - 2);
// }

//iterative
int climbStairs(int n) {
    int first = 1, second = 1, third, i;

    for (i = 1; i < n; i++) {
        third = first + second;
        first = second;
        second = third;
    }
    return second;
}
