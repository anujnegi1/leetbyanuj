class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        vector<int>vis;
        findcom(0,candidates,target,ans,vis);
        return ans;
    }
    void findcom(int i,vector<int>&c,int t,vector<vector<int>>&ans,vector<int>&vis)
    {
        if(t==0)
        {
            ans.push_back(vis);
            return;
        }
        for(int j=i;j<c.size();j++)
        {
            if(j>i && c[j]==c[j-1]) continue;
            if(c[j]>t) break;
            vis.push_back(c[j]);
            findcom(j+1,c,t-c[j],ans,vis);
            vis.pop_back();
        }
    }
};