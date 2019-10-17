class Solution {
public:
    // bit manipulation, same as single number, 4ms, 9MB
    char findTheDifference(string s, string t) {
        char res = 0;
        for(char c : s) res ^= c;
        for(char c : t) res ^= c;
        return res;
    }
    // 4ms, 8.9MB
    // char findTheDifference(string s, string t) {
    //     vector<int> count_s(26, 0);
    //     vector<int> count_t(26, 0);
    //     for(char c : s)
    //         count_s[c-'a']++;
    //     for(char c : t)
    //         count_t[c-'a']++;
    //     int i;
    //     for(i = 0; i < 26; ++i)
    //         if(count_t[i] > count_s[i])
    //             break;
    //     return 'a' + i;
    // }
};
