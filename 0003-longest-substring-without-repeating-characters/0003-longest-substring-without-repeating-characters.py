class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        left=0
        maxlen=0
        window=set()
        for right,ch in enumerate(s):
            while ch in window:
                window.remove(s[left])
                left+=1
            window.add(s[right])
            maxlen=max(maxlen,right-left+1)
        return maxlen
