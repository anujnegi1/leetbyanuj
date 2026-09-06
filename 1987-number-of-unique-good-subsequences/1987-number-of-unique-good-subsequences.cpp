class Solution {
public:
    int numberOfUniqueGoodSubsequences(string binary) {
       long long m=(1e9+7);
        long long  ew0=0,ew1=0;
        bool ans=false;
        for(char ch:binary)
        {
            if(ch=='1')
            {
                ew1=(ew0+ew1+1)%m;
            }
            else
            {
                ew0=(ew1+ew0)%m;
                ans=true;
            }
        }
        return (ew1+ew0+(ans?1:0))%m; 
    }
};