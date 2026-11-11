class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int low=0,high=n-1;
        int ans=INT_MAX;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            /*this is confition used for optimization.
            if arr is already sorted i.e both is left and right subarray are sorted */
            if(nums[low]<=nums[high])
            {
                ans=min(ans,nums[low]);
                break;
            }
            if(nums[low]<=nums[mid]) //left sorted
            {
                ans=min(ans,nums[low]);
                low=mid+1;
            }
            else{//right sorted
                ans=min(ans,nums[mid]);
                high=mid-1;
            }
        }
        return ans;
    }
};