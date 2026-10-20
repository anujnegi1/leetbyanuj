class Solution {
public:
    int egg(vector<vector<int>>&dp,int k,int n)
    {
        if(n<=1) return n;
        if(k==1) return n;
        if(dp[k][n]!=-1)
        {
            return dp[k][n];
        }
        int ans=INT_MAX;
        int a=1,b=n;
        while(a<=b)
        {
         int mid=a+(b-a)/2;
          int l=egg(dp,k-1,mid-1);
          int r=egg(dp,k,n-mid);
          int temp=1+max(l,r);
          ans=min(temp,ans);
          if(l<r)
          {
            a=mid+1;
          }
          else
          {
            b=mid-1;
          }
        }
        return dp[k][n]=ans;
    }
    int superEggDrop(int k, int n) {
        vector<vector<int>>dp(k+1,vector<int>(n+1,-1));
        return egg(dp,k,n);
    }
};