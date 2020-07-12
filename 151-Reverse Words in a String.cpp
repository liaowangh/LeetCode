class Solution {
public:
    string reverseWords(string s) {
        if(s.empty()) return s;
        helper(s, 0);
        reverse(s.begin(), s.end());
        int i = 0;
        while(s[i] == ' ') ++i;
        s.erase(0, i);
        return s;
    }
    
    void helper(string& s, int pos){
        // "hello world" -> "olleh dlrow"
        int n = s.size();
        if(pos >= n) return ;
        int begin_word = pos, end_word;
        while(begin_word < n && s[begin_word] == ' ') begin_word++;
        for(end_word = begin_word; end_word < n && s[end_word] != ' ';
            ++end_word){};
        reverse(s.begin() + begin_word, s.begin() + end_word);
        helper(s, end_word + 1);
        s.erase(pos, begin_word - pos);
        // erase(s.begin() + pos, begin_word - pos);
    }
};
