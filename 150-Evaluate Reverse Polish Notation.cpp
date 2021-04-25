class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        unordered_map<string, function<int(int,int)>> fun = {
            {"+", [](int a, int b){return a + b;}},
            {"-", [](int a, int b){return a - b;}},
            {"*", [](int a, int b){return a * b;}},
            {"/", [](int a, int b){return a / b;}}
        };
        for(auto token : tokens) {
            const auto& op = fun.find(token);
            if(op != fun.end()){
                int b = stk.top(); stk.pop();
                int a = stk.top(); stk.pop();
                stk.push((*op).second(a, b));
            } else
                stk.push(stoi(token));
        }
        return stk.top();
    }
};
// class Solution {
// public:
//     int evalRPN(vector<string>& tokens) {
//         stack<string> stk;
//         for(auto i : tokens) {
//             if(i == "+" || i == "-" || i == "*" || i == "/"){
//                 string right = stk.top();
//                 stk.pop();
//                 string left = stk.top();
//                 stk.pop();
//                 stk.push(expression(left, right, i));
//             } else{
//                 stk.push(i);
//             }
//         }
//         return stoi(stk.top());
//     }
    
//     string expression(string left, string right, string op) {
//         string res;
//         if(op == "+")
//             res = to_string(stoi(left)+stoi(right));
//         else if(op == "-")
//             res = to_string(stoi(left)-stoi(right));
//         else if(op == "*")
//             res = to_string(stoi(left)*stoi(right));
//         else if(op == "/")
//             res = to_string(stoi(left)/stoi(right));
//         return res;
//     }
// };
