class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int c=0;
        for(string &str:words)
        {
            if(str.find(pref)==0)
            {
                c++;
            }
        }
        return c;
    }
};