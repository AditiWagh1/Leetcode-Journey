class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        mpp=defaultdict(int)
        mpp[0]=1
        prefsum=0
        cnt=0
        for num in nums:
            prefsum+=num
            remove=prefsum-k
            cnt+=mpp[remove]
            mpp[prefsum]+=1
        return cnt