class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int pi;
        bool c=true;
        for(int i=0;i<nums.size();i++)
        {
            if(c && nums[i]==1)
            {
               c=false; 
               pi=i;
               continue;
            }
            if(nums[i]==1)
            {
                if(i-pi-1>=k) pi=i;
             else
                 return false;
            }
           
        }
        return true;
    }
};