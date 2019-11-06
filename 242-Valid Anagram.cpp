class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        vector<int> count(26, 0);
        for(int i = 0; i < t.size(); ++i){
            count[s[i]-'a']++;
            count[t[i]-'a']--;
        }
        for(int i = 0; i < 26; ++i)
            if(count[i])
                return false;
        return true;
    }
    // much faster, 8ms, 9.3MB
    // bool isAnagram(string s, string t) {
    //     if(s.size() != t.size()) return false;
    //     vector<int> s1(26, 0);
    //     vector<int> t1(26, 0);
    //     for(int i = 0; i < t.size(); ++i){
    //         s1[s[i]-'a']++;
    //         t1[t[i]-'a']++;
    //     }
    //     for(int i = 0; i < 26; ++i)
    //         if(s1[i] != t1[i])
    //             return false;
    //     return true;
    // }
    // sort, 28ms, 9.5MB
    // bool isAnagram(string s, string t) {
    //     sort(s.begin(), s.end());
    //     sort(t.begin(), t.end());
    //     return s == t;
    // }
};
