class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> pairindex;
        for(int i=0;i<nums.size();i++)
        {
            int num=nums[i];
            if(pairindex.find(target-num)!=pairindex.end())
            {
                return {i,pairindex[target-num]};
            }
            pairindex[num]=i;
        }
        return {};
    }
};