class Solution:
    def dailyTemperatures(self, t):
        ans = [0] * len(t)
        my_list = []
        for i in range(len(t)):
            while my_list and t[i] > t[cur := my_list[-1]]:
                ans[cur] = i - cur
                my_list.pop()
            else:
                my_list.append(i)
        return ans
