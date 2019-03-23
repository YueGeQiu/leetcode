class Solution:
    def climbStairs(self, n: int) -> int:
        first, second  = 0, 1
        for x in range(n):
            first = first + second
            first, second = second, first

        return second
