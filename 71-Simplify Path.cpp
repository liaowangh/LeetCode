class Solution {
public:
    string simplifyPath(string path) {
        string res;
        if(path.empty()) return res;
        stringstream ss(path);
        vector<string> stk;
        string tmp;
        while(getline(ss, tmp, '/')){
            if(tmp == "" || tmp == ".") continue;
            if(tmp == ".." && !stk.empty())
                stk.pop_back();
            else if(tmp != "..")
                stk.push_back(tmp);
        }
        for(auto s : stk) res += '/' + s;
        return res.empty() ? "/" : res;
    }
};
