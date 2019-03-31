class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        if word1 == None or word2 == None:
            return 0

        len1 = len(word1) + 1
        len2 = len(word2) + 1
        d = [[x + y if x == 0 or y == 0 else 0 for x in range(len2)] for y in range(len1)]
        for x in range(1, len1):
            for y in range(1, len2):
                if word1[x - 1] == word2[y - 1]:
                    d[x][y] = d[x - 1][y - 1]
                else:
                    d[x][y] = min(d[x - 1][y - 1], d[x][y - 1], d[x - 1][y]) + 1

        return d[len1 - 1][len2 - 1]
