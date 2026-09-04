class Solution {
public:
    bool sumGame(string num) {
        int n=num.size();
        int ls=0,rs=0;
        int lq=0,rq=0;
        for(int i=0;i<n/2;i++)
        {
            if(num[i]=='?') lq++;
            else ls+=num[i]-'0';
        }
        for(int i=n/2;i<n;i++)
        {
            if(num[i]=='?') rq++;
            else rs+=num[i]-'0';
        }
        int d1=ls-rs;
        int d2=lq-rq;

        if (d2==0)
            return d1!=0;

        return 2*d1!= -9*d2;
    }
};