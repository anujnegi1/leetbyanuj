class Solution {
public:
    int partitionString(string s) {
        vector<bool>vis(26,false);
        int c=1;
        for(int i=0;i<s.size();i++)
        {
            char ch=s[i];
            if(vis[ch-'a'])
            {
                for(int j=0;j<26;j++)
                {
                    vis[j]=false;
                }
                c++;
            }
            vis[ch-'a']=true;
        }
        return c;
    }
};