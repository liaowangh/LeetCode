class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        int n = s.size();
        string tmp;
        for(int i = 1; i < 4; ++i){
            for(int j = 1; j < 4; ++j){
                for(int k = 1; k < 4; ++k){
                    if(n-i-j-k>0 and n-i-j-k<4){
                        int a1 = stoi(s.substr(0,i));
                        int a2 = stoi(s.substr(i,j));
                        int a3 = stoi(s.substr(i+j,k));
                        int a4 = stoi(s.substr(i+j+k,n));
                        if(a1 < 256 and a2 < 256 and a3 < 256 and a4 < 256){
                            tmp = to_string(a1)+"."+to_string(a2)+"." +
                                          to_string(a3)+"."+
                                          to_string(a4);
                            if(tmp.size() == n + 3)
                                res.push_back(tmp);
                            
                        }
                    }
                }
            }
        }
        return res;
    }
    
    
};

 
