from collections import Counter
class Solution:
    def topKFrequent(self, nums, k: int):
        return [i[0] for i in Counter(nums).most_common(k)]
