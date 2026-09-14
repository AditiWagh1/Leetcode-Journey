class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        last_zero=0 #optimal approach
        for i in range(len(nums)):
            if nums[i]!=0:
                nums[last_zero],nums[i]=nums[i],nums[last_zero]
                last_zero+=1





        #better approach    
        # insert_pos=0
        # for num in nums:
        #     if num!=0:
        #         nums[insert_pos]=num
        #         insert_pos+=1

        # while insert_pos<len(nums):
        #     nums[insert_pos]=0
        #     insert_pos+=1
        