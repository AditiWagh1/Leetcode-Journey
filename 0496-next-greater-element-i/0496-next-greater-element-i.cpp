class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int,int> nextgreater;
        for(int i=nums2.size()-1;i>=0;i--)
        {
            int current=nums2[i];
            while(st.size()>0 && st.top()<=current) st.pop();
            if(st.empty())
            {
                nextgreater[current]=-1;
            }
            else{
                nextgreater[current]=st.top();
            }
            st.push(current);
        }
        vector<int> ans;
        for(int x:nums1)
        {
            ans.push_back(nextgreater[x]);
        }
        return ans;
    }
};