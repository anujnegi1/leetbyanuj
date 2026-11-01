class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        int m=queries.size(),n=nums.size();
        vector<long long>ans(m);
        sort(nums.begin(),nums.end());
        vector<long long>ps(nums.size()+1,0);
        for(int i=0;i<nums.size();i++)
        {
            ps[i+1]=ps[i]+nums[i];
        }
        for(int i=0;i<m;i++)
        {
            long long q=queries[i];
            auto a=lower_bound(nums.begin(),nums.end(),q);
            long long idx=distance(nums.begin(),a);
            long long ls=ps[idx];
            long long lo=q*idx-ls;
            long long rs=ps[n]-ps[idx];
            long long ro=rs-q*(n-idx);
            ans[i]=lo+ro;
        }
        return ans;

    }
};