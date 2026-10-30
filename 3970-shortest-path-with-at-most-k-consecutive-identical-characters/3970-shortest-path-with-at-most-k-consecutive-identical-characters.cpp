class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int,int>>>dp(n);
        for(auto &e:edges)
        {
            dp[e[0]].emplace_back(e[1],e[2]);
        }
        vector<int>arr(n,k+1);
        using s=tuple<long long,int,int>;
        priority_queue<s,vector<s>,greater<>>q;
        q.emplace(0,1,0);
        while(!q.empty())
        {
            auto[a,b,c]=q.top();
            q.pop();
            if(b>=arr[c])
            {
                continue;
            }
            if(c==n-1) return a;
            arr[c]=b;
            for(auto[x,y]:dp[c])
            {
                int r=labels[x]==labels[c]?b+1:1;
                if(r<arr[x])
                {
                    q.emplace(a+y,r,x);
                }
            }
        }
        return -1;
    }
};