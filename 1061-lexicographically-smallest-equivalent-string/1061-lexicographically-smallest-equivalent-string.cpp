class Solution {
public:
    char dfs(unordered_map<char,vector<char>>&adj,char ch,vector<int>&vis)
    {
        vis[ch-'a']=1;
        char a=ch;
        for(char c:adj[ch])
        {
            if(vis[c-'a']==0)
            {
                a=min(a,dfs(adj,c,vis));
            }
        }
        return a;
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n=s1.size();
        unordered_map<char,vector<char>>adj;
        for(int i=0;i<n;i++)
        {
            char a=s1[i],b=s2[i];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        string ans;
        for(auto ch:baseStr)
        {
            vector<int>vis(26,0);
            char a=dfs(adj,ch,vis);
            ans.push_back(a);
        }
        return ans;
    }
};