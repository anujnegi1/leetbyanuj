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
class Trie {
private: node*n;    
public:
    Trie() {
        n=new node();
    }
    
    void insert(string word) {
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
    
    bool search(string word) {
        node* temp=n;
        for(int i=0;i<word.size();i++)
        {
            if(!temp->contains(word[i]))
            {
                return false;
            }
            temp=temp->next(word[i]);
        }
        return temp->isend();
    }
    
    bool startsWith(string prefix) {
         node* temp=n;
        for(int i=0;i<prefix.size();i++)
        {
            if(!temp->contains(prefix[i]))
            {
                return false;
            }
            temp=temp->next(prefix[i]);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */