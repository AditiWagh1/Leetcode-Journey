class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0,r=height.size()-1;
        int maxarea=0;
        while(l<r)
        {
            int width=r-l;
            int minheight=min(height[l],height[r]);
             maxarea=max(maxarea,width*minheight);
            if(height[l]<=height[r])
            {
                l++;//we will choose minimum one karan tevdhech pani bharu sakte choty bamboo evdhe dusre kiti hi motha asla tari
            }
            else{
                r--;
            }
        }
        return maxarea;
    }
};//Tc=O(n) and SC=(1)
