class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        int s=0,ans=0;
        m[s]=1;
        for(auto it:nums)
        {
            s+=it;
            int f=s-k;
            if(m.find(f)!=m.end())
            {
                ans+=m[f];
            }
            m[s]++;
        }
        return ans;
    }
};