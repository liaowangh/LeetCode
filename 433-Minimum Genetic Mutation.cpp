class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        int res = -1;
        bfs(start, end, bank, 1, res);
        return res;
    }
    
    void bfs(const string& str, const string& end, vector<string>& bank, int nr,
             int& res) {
        if(nr > bank.size()) {
            return;
        }
        for(const string& s: bank) {
            if(count_difference(str, s) == 1) {
                if(s == end) {
                    if(res == -1 || nr < res)
                        res = nr;
                    return;
                } else{
                    bfs(s, end, bank, nr+1, res);
                }
            }
        }
    }
    
    int count_difference(const string& a, const string& b) {
        int count = 0;
        for(int i = 0; i < a.size(); ++i) {
            if(a[i] != b[i]) {
                count++;
            }
        }
        return count;
    }
};
