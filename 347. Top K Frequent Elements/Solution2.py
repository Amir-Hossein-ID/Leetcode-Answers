class Solution:
    def topKFrequent(self, nums, k: int):
        frd = {}
        for i in nums:
            if i in frd:
                frd[i]+=1
            else:
                frd[i] = 1
        num = {i:frd[i] for i in sorted(frd, key=lambda x: frd[x], reverse=True)}
        return list(num.keys())[:k]
