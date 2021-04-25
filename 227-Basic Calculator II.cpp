class Solution {
public:
    int calculate(string s) {
        stringstream ss("+" + s);
        int res = 0;
        char op;
        int num, last;
        while(ss >> op >> num) {
            if(op == '+' || op == '-') {
                num = op == '+' ? num : -num;
                res += num;
            } else {
                num = op == '*' ? last * num : last / num;
                res = res - last + num;
            }
            last = num;
        }
        return res;
    }
    
    // int calculate(string s) {
    //     stringstream ss("+" + s);
    //     stack<int> stk;
    //     stk.push(0);
    //     char op;
    //     int num;
    //     while(ss >> op >> num) {
    //         if(op == '+' || op == '-') {
    //             num = op == '+' ? num : -num;
    //             stk.push(num);
    //         } else {
    //             int tmp = stk.top();
    //             stk.pop();
    //             num = op == '*' ? tmp * num : tmp / num;
    //             stk.push(num);
    //         }
    //     }
    //     int res = 0;
    //     while(!stk.empty()) {
    //         res += stk.top();
    //         stk.pop();
    //     }
    //     return res;
    // }
};

// class Solution {
// private:
//     unordered_map<char, function<int(int,int)>> func{
//         {'+', [](int a, int b){return a + b;}},
//         {'-', [](int a, int b){return a - b;}},
//         {'*', [](int a, int b){return a * b;}},
//         {'/', [](int a, int b){return a / b;}}
//     };
    
//     unordered_map<char, int> optoi{{'+', 0}, {'-', 0}, {'*', 1}, {'/', 1}};
    
// public:
//     int calculate(string s) {
//         if(s.empty()) return 0;
//         int end = s.size();
//         int a = 0, b;
//         char op = '+', next_op;
//         int pos = -1, next_pos;
//         b = next_minus_plus(s, 0, end, next_pos, next_op);
//         while(next_pos < end) {
//             a = func[op](a, b);
//             op = next_op;
//             pos = next_pos;
//             b = next_minus_plus(s, pos + 1, end, next_pos, next_op);
//         }
//         return func[op](a, b);
//     }
    
//     int next_minus_plus(string& s, int start, int end, int& next_pos, char& next_op) {
//         // find the first + or - opearator in s[start~end), store the pos in next_pos
//         // and the operator in next_op
//         // return the result of s[start~next_pos)
//         int a = 1, b;
//         char op = '*';
//         int pos = start - 1;
//         for(int i = start; i < end; ++i) {
//             if(!optoi.count(s[i]))
//                 continue;
//             if(optoi[s[i]] == 0) {
//                 next_pos = i;
//                 next_op = s[i];
//                 b = string_to_int(s, pos + 1, i);
//                 return func[op](a, b);
//             } else {
//                 b = string_to_int(s, pos + 1, i);
//                 a = func[op](a, b);
//                 op = s[i];
//                 pos = i;
//             }
//         }
//         b = string_to_int(s, pos + 1, end);
//         next_pos = end;
//         return func[op](a, b);
//     }
        
//     int string_to_int(string& s, int start, int end) {
//         // return stoi(s[start~end))
//         return stoi(s.substr(start, end - start));
//     }
// };
