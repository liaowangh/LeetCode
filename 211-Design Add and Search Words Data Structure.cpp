class TrieNode {
public:
    bool word;
    TrieNode* next[26]{};
    TrieNode(): word(false) {}
};

class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary(): root(new TrieNode) {}
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode* node = root;
        for(char c : word) {
            if(!node->next[c-'a'])
                node->next[c-'a'] = new TrieNode();
            node = node->next[c-'a'];
        }
        node->word = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return search(word, 0, root);
    }
    
private:
    TrieNode* root;
    
    bool search(const string& word, int pos, TrieNode* node) {
        if(pos == word.size()) return node->word;
        if(word[pos] != '.') {
            TrieNode* tmp = node->next[word[pos]-'a'];
            return tmp ? search(word, pos+1, tmp) : false;
        } else {
            for(int j = 0; j < 26; ++j) {
                TrieNode* tmp = node->next[j];
                if(tmp && search(word, pos+1, tmp))
                    return true;
            }
        }
        return false;
    }
};

// class WordDictionary {
// public:
//     /** Initialize your data structure here. */
//     WordDictionary() {}
    
//     /** Adds a word into the data structure. */
//     void addWord(string word) {
//         words[word.size()].push_back(word);
//     }
    
//     /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
//     bool search(string word) {
//         for(auto s : words[word.size()])
//             if(isEqual(word, s))
//                 return true;
//         return false;
//     }
    
//     bool isEqual(string a, string b) {
//         for(int i = 0; i < a.size(); ++i){
//             if(a[i] == '.') continue;
//             if(a[i] != b[i]) return false;
//         }
//         return true;
//     }
    
// private:
//     unordered_map<int, vector<string>> words;
// };

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
