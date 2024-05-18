class Solution:
    def isPalindrome(self, s: str) -> bool:
        s = s.lower()
        s = [i for i in s if i.isalnum()]
        if s == s[::-1]:
            return True
        else:
            return False
