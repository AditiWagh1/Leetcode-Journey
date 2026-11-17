class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        pairindex={}
        for i,num in enumerate(nums):
            complement=target-num
            if complement in pairindex:
                return [pairindex[complement],i]
            pairindex[num]=i
        return [] 