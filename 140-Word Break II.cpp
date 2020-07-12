class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> res;
        unordered_map<int, vector<string>> record;
        return dfs(record, 0, s, wordDict);
    }
    
    vector<string> dfs(unordered_map<int, vector<string>>& record, int pos,
                       string& s, vector<string>& wordDict){
        int n = s.size();
        if(record.count(pos)) return record[pos];
        vector<string> res;
        for(auto& word : wordDict){
            int m = word.size();
            if(pos + m <= n && s.substr(pos, m) == word){
                if(pos + m == n) {
                    res.push_back(word);
                    continue;
                }
                vector<string> tmp = dfs(record, pos + m, s, wordDict);
                for(auto str : tmp){
                    res.push_back(word + " " + str);
                }
            }
        }
        record[pos] = res;
        return res;
    }
    
};
