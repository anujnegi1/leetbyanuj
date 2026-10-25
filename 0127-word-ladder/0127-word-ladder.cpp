class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>s(wordList.begin(),wordList.end());
        if(s.find(endWord)==s.end()) return 0;
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        s.erase(beginWord);
        while(!q.empty())
        {
            string str=q.front().first;
            int ans=q.front().second;
            q.pop();
            if(str==endWord) return ans;
            for(int i=0;i<str.size();i++)
            {
                char ch=str[i];
                for(char c='a';c<='z';c++)
                {
                    str[i]=c;
                    if(s.find(str)!=s.end())
                    {
                        q.push({str,ans+1});
                        s.erase(str);
                    }
                }
                str[i]=ch;
            }
        }
      return 0;
    }
};