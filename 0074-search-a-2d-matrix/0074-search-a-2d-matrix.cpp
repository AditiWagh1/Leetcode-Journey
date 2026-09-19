class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //brute force in atoz dsa list
        int n=matrix.size();
        int m=matrix[0].size();
        int low=0,high=n*m-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            int row=mid/m;
            int col=mid%m;
            if(matrix[row][col]==target)
            {
                return true;
            }
            else if(matrix[row][col]<target)
            {
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return false;//TL=O(log2 n*m) SL=O(1)
    }
};