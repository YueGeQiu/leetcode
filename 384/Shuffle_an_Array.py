import random
class Solution:

    def __init__(self, nums: List[int]):
        self.nums = nums[:]

    def reset(self) -> List[int]:
        """
        Resets the array to its original configuration and return it.
        """
        return self.nums

    def shuffle(self) -> List[int]:
        """
        Returns a random shuffling of the array.
        """
        ret = self.nums[:]
        for item in range(len(ret) - 1, -1, -1):
            x = random.randint(0, item)
            ret[x], ret[item] = ret[item], ret[x]

        return ret

# Your Solution object will be instantiated and called as such:
# obj = Solution(nums)
# param_1 = obj.reset()
# param_2 = obj.shuffle()