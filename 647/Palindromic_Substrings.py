class Solution:
    def dp(self, s: str) -> int:
        length = len(s)
        res = 0

        d = [[False for x in range(length)] for y in range(length)]

        for x in range(length - 1, -1, -1):
            for y in range(x, length):
                if x == y:
                    d[x][y] = True
                elif x + 1 == y and s[y] == s[x]:
                    d[x][y] = True
                else:
                    d[x][y] = s[x] == s[y] and d[x + 1][y - 1]

                if d[x][y]:
                    res += 1

        return res

    def expand(self, s: str, left: int, right: int) -> int:
        length = len(s)
        res = 0

        while left >= 0 and right < length and s[left] == s[right]:
            res += 1
            left -= 1
            right += 1

        return res

    def countSubstrings(self, s: str) -> int:
        if not s or len(s) == 0:
            return 0

        # solution 1
        # return self.dp(s)

        # solution 2
        length = len(s)
        res = 0

        for x in range(length):
            res += self.expand(s, x, x)
            res += self.expand(s, x, x + 1)

        return res
