"""
author: yanb
"""
class Solution:
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        look_up = {}
        for idx, num in enumerate(nums):
            diff = target - num
            if diff in look_up:
                return [look_up[diff], idx]
            else:
                look_up[num] = idx
        return