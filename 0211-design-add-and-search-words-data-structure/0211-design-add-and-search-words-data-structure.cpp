struct node
{
    node* links[26]={NULL};
    bool f=false;
    bool isend()
    {
        return f;
    }
    void setend()
    {
        f=true;
    }
    void put(char ch,node* n)
    {
        links[ch-'a']=n;
    }
    node* next(char ch)
    {
        return links[ch-'a'];
    }
    bool contains(char ch)
    {
        return(links[ch-'a']!=NULL);
    }
};
class WordDictionary {
private: node*n;
public:
    WordDictionary() {
          n=new node();
    }
    
    void addWord(string word) {
        node *temp=n;
        for(int i=0;i<word.size();i++)
        {
            if(!temp->contains(word[i]))
            {
                temp->put(word[i],new node());
            }
            temp=temp->next(word[i]);
        }
        temp->setend();
    }
    
    
bool solve(node* temp,string word,int i)
{
    if(i==word.size())
    {
        return temp->isend();
    }
    if(word[i]=='.')
    {
        for(int j=0;j<26;j++)
        {
            if(temp->links[j]!=NULL)
            {
                if(solve(temp->links[j],word,i+1))
                {
                    return true;
                }
            }
        }
        return false;
    }
    if(!temp->contains(word[i]))
    {
        return false;
    }
    return solve(temp->next(word[i]),word,i+1);
}
bool search(string word)
{
    return solve(n,word,0);
}

};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */