class TrieNode {
public:
    bool isWord;
    TrieNode* next[26] = {};
    TrieNode(): isWord(false){}
};

void buildTrie(vector<string>& words, TrieNode* root) {
    for(string word: words) {
        TrieNode* node = root;
        for(char c : word) {
            if(!node->next[c-'a']) node->next[c-'a'] = new TrieNode();
            node = node->next[c-'a'];
        }
        node->isWord = true;
    }
}

class Solution {
public:
    vector<pair<int,int>> dir = {{1,0}, {0,1}, {-1,0}, {0,-1}};
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        unordered_set<string> res;
        if(board.empty() || board[0].empty() || words.empty())
            return vector<string>(res.begin(), res.end());
        TrieNode* root = new TrieNode();
        buildTrie(words, root);
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                visited[i][j] = 1;
                dfs(board, {i, j}, root, res, "", visited);
                visited[i][j] = 0;
            }
        }
        return vector<string>(res.begin(), res.end());
    }
    
    void dfs(vector<vector<char>>& board, pair<int,int> pos, TrieNode* node,
             unordered_set<string>& res, string tmp, vector<vector<int>>& visited) {
        int row = pos.first, col = pos.second;
        char c = board[row][col];
        TrieNode* nextNode = node->next[c-'a'];
        if(!nextNode) return;
        else{
            tmp.push_back(c);
            if(nextNode->isWord) res.insert(tmp);
            for(auto d : dir){
                if(inBoundary(pos, d, board.size(), board[0].size(),visited)){
                    int newrow = row + d.first;
                    int newcol = col + d.second;
                    visited[newrow][newcol] = 1;
                    dfs(board, {newrow, newcol}, nextNode, res, tmp, visited);
                    visited[newrow][newcol] = 0;
                }
            }
        }
    }
    
    bool inBoundary(pair<int,int> pos, pair<int,int> d, int m, int n,
                    vector<vector<int>>& visited) {
        int i = pos.first + d.first;
        int j = pos.second + d.second;
        if(i < 0 || i >= m || j < 0 || j >= n || visited[i][j])
            return false;
        return true;
    }
};
