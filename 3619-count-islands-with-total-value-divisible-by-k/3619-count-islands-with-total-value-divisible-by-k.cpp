class Solution {
public:
    long dfs(int i,int j,vector<vector<int>>& grid)
    {
        int m=grid.size();
        int n=grid[0].size();
        if(i<0||i>=m||j<0||j>=n||grid[i][j]==0) return 0;
        long ans=grid[i][j];
        grid[i][j]=0;
        ans+=dfs(i+1,j,grid);
        ans+=dfs(i-1,j,grid);
        ans+=dfs(i,j+1,grid);
        ans+=dfs(i,j-1,grid);
        return ans;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        int c=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]!=0)
                {
                    long res=dfs(i,j,grid);
                    if(res%k==0)
                    {
                        c++;
                    }
                }

            }
        }
        return c;
    }
};