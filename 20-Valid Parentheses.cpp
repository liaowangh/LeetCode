class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        std::stack<char> T;
        for(int i = 0; i < n; ++i) {
            if(s[i] == '[' || s[i] == '(' || s[i] == '{')
                T.push(s[i]);
            else if(T.empty())
                return false;
            else if(s[i] == ']' && T.top() == '[')
                T.pop();
            else if(s[i] == ')' && T.top() == '(')
                T.pop();
            else if(s[i] == '}' && T.top() == '{')
                T.pop();
            else
                return false;
        }
        if(T.empty())
            return true;
        return false;
    }
};
