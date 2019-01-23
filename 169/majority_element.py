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
        count = 1
        major = nums[0]
        for i in nums[1:]:
            if i != major:
                count -= 1
                if count == 0:
                    # reset
                    count = 1
                    major = i
            else:
                count += 1

        return major


