class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size()<2) return 0;
        sort(nums.begin(),nums.end());
        int ans=nums[1]-nums[0];
        for(int i=2;i<nums.size();i++)
        {
            int dif=nums[i]-nums[i-1];
            if(ans<dif) ans=dif;
        }
        return ans;
    }
};