class Solution {
public:
    long long countCommas(long long n) {
        if(n<1000) return 0;
       long long ans=0;
       long long s=1000;
       while(s<=n)
       {
          ans+=n-s+1;
          s*=1000;
       }
       return ans;
    }
};