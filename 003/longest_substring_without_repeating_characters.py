class Solution:

    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        current_string = set()
        max_length = 0
        i = j = 0  # sliding indexes

        while i < len(s) and j < len(s):
            
            if s[j] not in current_string:
                current_string.add(s[j])
                j += 1
                max_length = max(j - i, max_length)
            else:
               current_string.remove(s[i])
               i += 1
        
        return max_length


if __name__ == '__main__':
    s = Solution()
    i = s.lengthOfLongestSubstring("abcabcbb")
    print(i)