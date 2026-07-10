class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
       vector<int>ans(nums.size(),0);
       int c=0;
       while(c<nums.size())
       {
          int i=0;
          while(i<nums.size())
          {
              if(nums[c]>nums[i])
              {
                ans[c]++;
              }
              i++;
           }
           c++;
       }
       return ans;
    }
};