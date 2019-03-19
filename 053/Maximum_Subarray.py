class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        res = float("-inf")
        tmp_sum = 0

        for x in nums:
            if tmp_sum < 0:
                tmp_sum = x
            else:
                tmp_sum += x

            if tmp_sum > res:
                res = tmp_sum

        return res
