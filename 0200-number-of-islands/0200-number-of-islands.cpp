class Solution {
public:
    void solve(int i,int j,vector<vector<char>>& grid,vector<vector<bool>>& vis,int n,int m)
    {
        if(i<0||j<0||i>=n||j>=m) return;
        if(grid[i][j]=='0') return;
        if(vis[i][j]) return;
        vis[i][j]=true;
        solve(i-1,j,grid,vis,n,m);//top
        solve(i,j+1,grid,vis,n,m);//right
        solve(i+1,j,grid,vis,n,m);//bottom
        solve(i,j-1,grid,vis,n,m);//top
    }
    int numIslands(vector<vector<char>>& grid) {
        int islands=0;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1' && !vis[i][j])
                {
                    solve(i,j,grid,vis,n,m);
                    islands++;
                }
            }
        }
        return islands;
    }
};