class Solution:
    def groupAnagrams(self, strs):
        strs2 = ["".join(sorted(i)) for i in strs]
        l = {}
        for i in range(len(strs)):
            if strs2[i] in l:
                l[strs2[i]].append(strs[i])
            else:
                l[strs2[i]] = [strs[i]]
        return [i for i in l.values()]
