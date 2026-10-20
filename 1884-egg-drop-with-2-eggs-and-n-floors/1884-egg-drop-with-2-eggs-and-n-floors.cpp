class Solution {
public:
    int twoEggDrop(int n) {
        for(int i=1;i<=n;i++)
        {
            if((i*i)+i>=n*2)
            {
                return i;
            }
        }
        return -1;
    }
};