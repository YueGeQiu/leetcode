import math


class Solution:

    def majorityElementBrutalForce(self, nums: list):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums:
            return
        threshhold = math.floor(len(nums) / 2.0)
        # cache
        checked = set()
        for i in nums:
            if i in checked:
                continue
            else:
                checked.add(i)
            count = nums.count(i)
            if count > threshhold:
                return i

    def majorityElement(self, nums: list):
        if not nums:
            return
        pass
