class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n=s.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int l=1;l<=n;l++){
            for(int i=0,j=i+l-1;j<n;i++,j++){
                if(i==j)
                    dp[i][j]=1;
                else if(s[i]==s[j])
                    dp[i][j]=2+dp[i+1][j-1];
                else
                    dp[i][j]=max(dp[i+1][j],dp[i][j - 1]);
            }
        }
        return dp[0][n - 1];
    }
};