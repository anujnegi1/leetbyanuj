class Solution {
public:
    bool checkDivisibility(int n) {
        int ds=0,dp=1,ans=n;
        while(n>0)
        {
            int a=n%10;
            ds+=a; dp=dp*a;
            n=n/10;
        }
        int d=ds+dp;
        return ans%d==0;
    }
};