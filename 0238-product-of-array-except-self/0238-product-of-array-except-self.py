class Solution:
    def productExceptSelf(self, nums: list[int]) -> list[int]:
        n=len(nums)
        ans=[1]*n

        cur_prefix=1
        for i in range(n):
            ans[i]=cur_prefix
            cur_prefix*=nums[i]
        
        cur_sufix=1
        for i in range(n-1,-1,-1):
            ans[i]*=cur_sufix
            cur_sufix*=nums[i]
        
        return ans
