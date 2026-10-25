class Solution {
public:
    void dfs(vector<vector<char>>& board,int i,int j,vector<vector<bool>>&vis)
    {
        int m=board.size();
        int n=board[0].size();
        if(i<0||i>=m||j<0||j>=n||vis[i][j]==1||board[i][j]=='X') return;
        vis[i][j]=true;
        dfs(board,i+1,j,vis);
        dfs(board,i-1,j,vis);
        dfs(board,i,j+1,vis);
        dfs(board,i,j-1,vis);

    }
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        if(m==0) return;
        int n=board[0].size();
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        for(int i=0;i<m;++i)
        {
            if(board[i][0]=='O' && !vis[i][0]) dfs(board,i,0,vis);
            if(board[i][n-1]=='O' && !vis[i][n-1]) dfs(board,i,n-1,vis);
        }
        for(int i=0;i<n;++i)
        {
            if(board[0][i]=='O' && !vis[0][i]) dfs(board,0,i,vis);
            if(board[m-1][i]=='O' && !vis[m-1][i]) dfs(board,m-1,i,vis);
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]=='O' && !vis[i][j])
                {
                    board[i][j]='X';
                }
            }
        }
    }
};