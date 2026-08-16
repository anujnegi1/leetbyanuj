class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int i=0,j=0,k=0;
        for(auto it:stones)
        {
            if(it%3==0) i++;
            else if(it%3==1) j++;
            else k++;
        }
        if(i%2==0) return j>0&&k>0;
        return abs(j-k)>2;
       
    }
};