class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> m;
        unordered_set<char> r;
        for(int i = 0; i < s.size(); ++i) {
            if(m.count(s[i])){
              if(m[s[i]] != t[i]) return false;
            } else{
                if(r.count(t[i])) return false;
                m[s[i]] = t[i];
                r.insert(t[i]);
            }
        }
        return true;
    }
};
