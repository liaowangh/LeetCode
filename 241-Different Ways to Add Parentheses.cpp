class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        unordered_map<string, vector<int>> m;
        // m.push({"", vector<int>()});
        m[""] = vector<int>();
        return helper(input, m);
    }
    
    vector<int> helper(string input, unordered_map<string, vector<int>>& m){
        if(m.count(input))
            return m[input];
        if(input.size() == 1){
            m[input] = vector<int>{stoi(input)};
            return m[input];
        }
        bool has_op = false;
        vector<int> res;
        for(int i = 0; i < input.size(); ++i){
            if(!isdigit(input[i])){
                has_op = true;
                vector<int> left_res = helper(input.substr(0, i), m);
                vector<int> right_res = helper(input.substr(i+1), m);
                for(auto l : left_res){
                    for(auto r: right_res){
                        int tmp;
                        if(input[i] == '+')
                            tmp = l + r;
                        else if(input[i] == '-')
                            tmp = l - r;
                        else if(input[i] == '*')
                            tmp = l * r;
                        res.push_back(tmp);
                    }
                }
            }
        }
        if(!has_op)
            res.push_back(stoi(input));
        m[input] = res;
        return res;
    }
};

// class Solution {
// public:
//     vector<int> diffWaysToCompute(string input) {
//         vector<int> res;
//         if(input.empty()) return res;
//         if(input.size() == 1){
//             res.push_back(stoi(input));
//             return res;
//         }
//         bool has_op = false;
//         for(int i = 0; i < input.size(); ++i){
//             if(!isdigit(input[i])){
//                 has_op = true;
//                 vector<int> left_res = diffWaysToCompute(input.substr(0, i));
//                 vector<int> right_res = diffWaysToCompute(input.substr(i+1));
//                 for(auto l : left_res){
//                     for(auto r: right_res){
//                         int tmp;
//                         if(input[i] == '+')
//                             tmp = l + r;
//                         else if(input[i] == '-')
//                             tmp = l - r;
//                         else if(input[i] == '*')
//                             tmp = l * r;
//                         res.push_back(tmp);
//                     }
//                 }
//             }
//         }
//         if(!has_op)
//             res.push_back(stoi(input));
//         return res;
//     }
// };
