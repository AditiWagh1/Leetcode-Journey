class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReachable = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            // If the current index is beyond our maximum reach, we are stuck
            if (i > maxReachable) {
                return false;
            }
            
            // Update the furthest index we can reach from here
            maxReachable = max(maxReachable, i + nums[i]);
            
            // Optimization: If we can already reach the end, stop early
            if (maxReachable >= nums.size() - 1) {
                return true;
            }
        }
        
        return true;
    }
};