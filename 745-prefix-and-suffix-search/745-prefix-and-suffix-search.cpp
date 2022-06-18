class WordFilter {
public:
    unordered_map<string, int> mp;
    WordFilter(vector<string>& words) {
        
        int n = words.size();
        for (int i = 0; i < n; i++) {
            string word = words[i];
			
            for (int j = 1;j<=word.size();j++) {
                string prefix = word.substr(0,j);
				
                for (int k = 0;k<word.size();k++) {
                    string suffix = word.substr(k, word.size());

                    mp[prefix + "*" + suffix] = i + 1;
                }
            }
        }
    }

    int f(string prefix, string suffix) {
        string s = prefix + "*" + suffix;
        return mp[s] - 1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */