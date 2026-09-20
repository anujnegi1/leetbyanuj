class Solution {
public:
    int reverseDegree(string s) {
        int sum=0;
        for(int i=0;i<s.length();i++){
            char ch=s[i];
            int a=26-(ch-'a');
            int b=i+1;
            sum+=a*b;
        }
        return sum;
    }
};