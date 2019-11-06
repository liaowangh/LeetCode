class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> letters(26, -1);
        int n = s.size();
        for(int i = 0; i < n; ++i){
            if(letters[s[i]-'a'] == -2) // s[i] has already appeared twice
                continue;
            else if (letters[s[i]-'a'] == -1) // the first time s[i] appears
                letters[s[i]-'a'] = i;
            else
                letters[s[i]-'a'] = -2;  // s[i] appears twice, set to -2
        }
        int res = n;
        for(int i : letters)
            if(i >= 0)
                res = min(res, i);
        return res == n ? -1 : res;
    }
    // 72ms, 12.9MB
    // int firstUniqChar(string s) {
    //     unordered_map<char, int> map;
    //     for(int i = 0; i < s.size(); ++i)
    //         map[s[i]] = i;
    //     for(int i = 0; i < s.size(); ++i){
    //         if(map[s[i]] == i) return i;
    //         map[s[i]] = i;
    //     }
    //     return -1;
    // }
};
