class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis = grid;
        queue<pair<int,int>> q;

        int cfo = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(vis[i][j] == 2)
                    q.push({i, j});

                if(vis[i][j] == 1)
                    cfo++;
            }
        }

        if(cfo == 0) return 0;
        if(q.empty()) return -1;

        int ans = -1;

        vector<pair<int,int>> dir = {
            {1,0}, {-1,0}, {0,1}, {0,-1}
        };

        while(!q.empty()) {
            int s = q.size();

            while(s--) {
                auto [x, y] = q.front();
                q.pop();

                for(auto [a, b] : dir) {
                    int i = x + a;
                    int j = y + b;

                    if(i >= 0 && i < n &&
                       j >= 0 && j < m &&
                       vis[i][j] == 1) {

                        vis[i][j] = 2;
                        cfo--;
                        q.push({i, j});
                    }
                }
            }
            ans++;
        }

        return (cfo == 0) ? ans : -1;
    }
};