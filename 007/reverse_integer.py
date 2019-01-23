class Solution:
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        if x >= 0:
            ret = int(str(x)[::-1]) * (x < 2**31)
        else:
            ret = -1 * int(str(-1 * x)[::-1]) * (x < 2**31)
        
        # kind of shit, handle the overflow case
        if ret.bit_length() >= 32:
            return 0
        else:
            return ret