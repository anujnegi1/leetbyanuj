class Solution {
public:
   bool dfs(vector<vector<char>>& board, string word,int i,int j,int k)
   {
      int m=board.size();
      int n=board[0].size();
      if(k==word.size()) return true;
      if(i<0||j<0||i>=m||j>=n) return false;
      if(board[i][j]!=word[k]) return false;
      char ch=board[i][j];
      board[i][j]='#';
      if(dfs(board,word,i+1,j,k+1)||dfs(board,word,i-1,j,k+1)||dfs(board,word,i,j+1,k+1)||
      dfs(board,word,i,j-1,k+1))
      {
        board[i][j]=ch;
        return true;
      }
      board[i][j]=ch;
      return false;
   }
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(dfs(board,word,i,j,0))
                {
                    return true;
                }
            }
        }
        return false;
    }
};