class Solution {
public:
    int minMoves(vector<int>& nums) {
        int m=*max_element(nums.begin(),nums.end());
        int ans=0;
        for(auto it:nums)
        {
            ans+=m-it;
        }
        return ans;
    }
};