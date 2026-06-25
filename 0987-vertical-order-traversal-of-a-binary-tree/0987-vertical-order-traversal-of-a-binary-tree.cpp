/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
         vector<tuple<int,int,int>>n;
         dfs(root,0,0,n);
         sort(n.begin(),n.end());
         vector<vector<int>>res;
         int p=INT_MIN;
         for(auto[c,r,v]:n)
         {
            if(c!=p)
            {
                res.push_back({});
                p=c;
            }
            res.back().push_back(v);
         }
         return res;

    }
    void dfs(TreeNode*r,int r1,int c,vector<tuple<int,int,int>>&n)
    {
        if(!r) return;
        n.emplace_back(c,r1,r->val);
        dfs(r->left,r1+1,c-1,n);
        dfs(r->right,r1+1,c+1,n);
    }
};