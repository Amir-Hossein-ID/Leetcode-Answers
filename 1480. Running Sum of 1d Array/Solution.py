class Solution:
    def runningSum(self, nums):
        s = []
        sum = 0
        for i in nums:
            sum+=i
            s.append(sum)

        return s
