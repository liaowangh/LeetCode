class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> fre(128, 0);
        for(char c : t){
            fre[c - '\0']++;
        }
        for(char i : s){
            fre[i - '\0']--;
        }
        for(int i = 0; i < 128; ++i)
            if(fre[i] > 0)
                return string("");
        int left = 0;
        int right = s.size() - 1;
        int res_left, res_right;
        int min_len = INT_MAX;
        
        while(fre[s[right] - '\0'] < 0)
            fre[s[right--] - '\0']++;
       
        while(true){
            while(fre[s[left] - '\0'] < 0)
                fre[s[left++] - '\0']++;
            if(right - left < min_len){
                min_len = right - left;
                res_left = left;
                res_right = right;
            }
            if(++right == s.size()) break;
            fre[s[right] - '\0']--;
        }
        return string(s.begin() + res_left, s.begin() + res_right + 1);
    }
};
