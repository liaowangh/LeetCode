class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        T = set<string>();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        T.insert(word);
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        if (T.empty()) return false;
        return T.find(word) != T.end();
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        if(T.empty()) return false;
        auto c = T.lower_bound(prefix);
        if (c == T.end()) return false;
        return c->substr(0, prefix.size()) == prefix;
    }
private:
    set<string> T;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
