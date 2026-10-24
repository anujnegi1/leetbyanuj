class Solution {
    struct node{
        node *links[26]={};
        string *anuj=NULL;
    };
    int m,n;
    vector<string>ans;
    void dfs(vector<vector<char>>& board,int i,int j,node *n1)
    {
        if(i<0||i>=m||j<0||j>=n||board[i][j]=='#') return;
        char ch=board[i][j];
        if(!n1->links[ch-'a']) return;
        n1=n1->links[ch-'a'];
        if(n1->anuj)
        {
            ans.push_back(*n1->anuj);
            n1->anuj=nullptr;
        }
        board[i][j]='#';
        dfs(board,i+1,j,n1);
        dfs(board,i-1,j,n1);
        dfs(board,i,j+1,n1);
        dfs(board,i,j-1,n1);
        board[i][j]=ch;
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        m=board.size();
        n=board[0].size();
        node *n1=new node();
        for(auto &ch:words)
        {
            auto n2=n1;
            for(char c:ch)
            {
                if(!n2->links[c-'a'])
                {
                    n2->links[c-'a']=new node();
                }
                n2=n2->links[c-'a'];
            }
            n2->anuj=&ch;
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                dfs(board,i,j,n1);
            }
        } 
        return ans;  
     }
};