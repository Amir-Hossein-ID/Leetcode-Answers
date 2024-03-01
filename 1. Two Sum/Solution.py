class Solution:
    def twoSum(self, nums, target: int):
        for i in range(len(nums)):
            if target - nums[i] in nums[i+1:]:
                s = nums.index(target - nums[i], i+1)
                if s != -1:
                    return [i, s]
