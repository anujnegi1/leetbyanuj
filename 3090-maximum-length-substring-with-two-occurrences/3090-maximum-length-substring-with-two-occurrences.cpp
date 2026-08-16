class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char,int>vis;
        int i=0,j=0,n=s.size();
        int ans= 0;    
        while(j<n) {
            vis[s[j]]++;
            while(vis[s[j]]>2) {
                vis[s[i]]--;
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};