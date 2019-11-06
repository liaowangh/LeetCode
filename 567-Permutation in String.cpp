class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.size() < s1.size()) return false;
        vector<int> fre_s1(26, 0);
        for(char c : s1)
            fre_s1[c-'a']++;
        for(int i = 0; i < s1.size(); ++i)
            fre_s1[s2[i]-'a']--;
        if(all_zero(fre_s1)) return true;
        for(int i = s1.size(); i < s2.size(); ++i){
            fre_s1[s2[i]-'a']--;
            fre_s1[s2[i-s1.size()]-'a']++;
            if(all_zero(fre_s1)) return true;
        }
        return false;
    }
    
    bool all_zero(const vector<int>& a){
        for(int i : a)
            if(i != 0)
                return false;
        return true;
    }
    
//     bool checkInclusion(string s1, string s2) {
//         if(s2.size() < s1.size()) return false;
//         for(int i = 0; i + s1.size() <= s2.size(); ++i)
//             if(is_permutation(s1, s2.substr(i,s1.size())))
//                 return true;
//         return false;
//     }
    
//     bool is_permutation(string s1, string s2){
//         // check whether s2 is a permutation of s1
//         if(s1.size() != s2.size()) return false;
//         vector<int> fre(26, 0);
//         for(int i = 0; i < s1.size(); ++i){
//             fre[s1[i]-'a']++;
//             fre[s2[i]-'a']--;
//         }
//         for(int i : fre)
//             if(i != 0)
//                 return false;
//         return true;
//     }
};
