class Solution {
public:
    int countEven(int num) {
        int t=num,sum=0;
        while(num>0)
        {
            sum+=num%10;
            num=num/10;
        }
        if(sum%2==0) return t/2;
        return (t-1)/2;
    }
};