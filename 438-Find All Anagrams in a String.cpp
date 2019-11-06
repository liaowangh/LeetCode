class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        if(p.size() == 0 || s.size() < p.size()) return res;
        vector<int> fre_p(26, 0);
        for(char c : p)
            fre_p[c-'a']++;
        int n = p.size();
        int diff = n;
        for(int i = 0; i < n; ++i){
            int tmp = s[i] - 'a';
            fre_p[tmp]--;
            if(fre_p[tmp] >= 0) diff--;
        }
        if(diff == 0) res.push_back(0);
        for(int i = n; i < s.size(); ++i){
            int start = s[i-n]-'a';
            if(fre_p[start] >= 0) diff++;
            fre_p[start]++;
            
            int end = s[i] - 'a';
            fre_p[end]--;
            if(fre_p[end] >= 0) diff--;
            if(diff == 0) res.push_back(i-n+1);
        }
        return res;
    }
    
    // vector<int> findAnagrams(string s, string p) {
    //     vector<int> res;
    //     if(s.size() < p.size()) return res;
    //     vector<int> fre_p(26, 0);
    //     for(char c : p)
    //         fre_p[c-'a']++;
    //     int n = p.size();
    //     for(int i = 0; i < n; ++i)
    //         fre_p[s[i]-'a']--;
    //     if(all_zero(fre_p)) res.push_back(0);
    //     for(int i = n; i < s.size(); ++i){
    //         fre_p[s[i]-'a']--;
    //         fre_p[s[i-n]-'a']++;
    //         if(all_zero(fre_p)) res.push_back(i-n+1);
    //     }
    //     return res;
    // }
    
    // bool all_zero(const vector<int>& a){
    //     for(int i : a)
    //         if(i != 0)
    //             return false;
    //     return true;
    // }
};
