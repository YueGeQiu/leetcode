class Solution:
    def dp(self, s: str) -> str:
        length = len(s)
        start, maxLen = 0, 0
        d = [[False for x in range(length)] for y in range(length)]
        for x in range(length - 1, -1, -1):
            for y in range(x, length):
                if x == y:
                    d[x][y] = True
                elif x + 1 == y:
                    d[x][y] = s[x] == s[y]
                elif s[x] == s[y]:
                    d[x][y] = d[x + 1][y - 1]

                if d[x][y] and y - x + 1 > maxLen:
                    start, maxLen = x, y - x + 1

        return s[start:start + maxLen]

    def expand(self, s: str, left: int, right: int) -> int:
        length = len(s)
        while left >= 0 and right < length and s[left] == s[right]:
            left -= 1
            right += 1

        # (right - 1) - (left + 1) + 1
        return right - left - 1


    def longestPalindrome(self, s: str) -> str:
        if not s or len(s) < 2:
            return s

        # dp
        # return self.dp(s)

        # expand
        length = len(s)
        start, maxLen = 0, 0

        for x in range(length):
            len1 = self.expand(s, x, x)
            len2 = self.expand(s, x, x + 1)
            len3 = max(len1, len2)
            if len3 > maxLen:
                maxLen = len3
                start = x - (maxLen - 1) // 2

        return s[start:start + maxLen]