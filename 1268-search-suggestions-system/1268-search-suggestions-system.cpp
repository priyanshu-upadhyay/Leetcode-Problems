class Trie
{
    public:
        Trie* child[26];
        bool flag;
        Trie()
        {
            flag = false;
            for(int i = 0; i < 26; i++)
            {
                child[i] = NULL;
            }
        }
};

class Solution {
private:
    Trie* root = NULL;
public:
    
    void insert(string word)
    {
        if(root == NULL)
        {
            root = new Trie();
        }
        
        Trie* curr = root;
        for(int i = 0; i < word.length(); i++)
        {
            int pos = word[i] - 'a';
            
            if(curr->child[pos] == NULL)
            {
                curr->child[pos] = new Trie();
            }
            curr = curr->child[pos];
        }
        curr->flag = true;
    }
    
    
    void genrateWord(Trie* curr, vector<string> &arr, string temp)
    {
        if(arr.size() < 3 && curr->flag == true)
        {
            arr.push_back(temp);
        }
        if(arr.size() >= 3) return;
        
        for(int i = 0; i < 26; i++)
        {
            if(curr->child[i])
            {
                genrateWord(curr->child[i], arr, temp + (char)(i+'a'));
                if(arr.size() >= 3) return;
            }
        }
    }
    
    vector<vector<string>> searchWords(string word)
    {
        if(root == NULL)
        {
            return {{}};
        }
        
        vector<vector<string>> result;
        
        Trie* curr = root;
        string temp = "";
        for(int i = 0; i < word.length(); i++)
        {
            int pos = word[i] - 'a';
            if(curr->child[pos] == NULL)
            {
                return result;
            }
            temp = temp + word[i];
            vector<string> inner;
            curr = curr->child[pos];
            genrateWord(curr, inner, temp);
            result.push_back(inner);;
        }
        return result;
        
    }
        
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        // sort(products.begin(), products.end());
        for(int i = 0; i < products.size(); i++)
        {
            insert(products[i]);
        }
        
        vector<vector<string>> res = searchWords(searchWord);
        int n = res.size(), m = searchWord.length();
        if(n < m)
        {
            for(int i = 0; i <m-n; i++)
            {
                res.push_back({});
            }
        }
        return res;
        
    }
};