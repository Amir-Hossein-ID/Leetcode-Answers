from collections import Counter
import heapq
class Solution:
    def topKFrequent(self, nums, k: int):
        x = [(i[1], i[0]) for i in Counter(nums).items()]
        heapq.heapify(x)
        return [i[1] for i in heapq.nlargest(k, x)]
