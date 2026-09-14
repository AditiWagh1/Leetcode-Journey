class Solution:
    def isPalindrome(self, s: str) -> bool:
        left,right=0,len(s)-1 #optimal TC=O(n) & Sc=O(1)
        while left<right:
            while left<right and not s[left].isalnum():
                left+=1
            while left<right and not s[right].isalnum():
                right-=1
            if s[left].lower()!=s[right].lower():
                return False
            left+=1
            right-=1
        return True


        #python fluent optimal approach TC & Sc=O(n)
        # cleaned= [ch.lower() for ch in s if ch.isalnum()]
        # return cleaned==cleaned[::-1]
