class Solution {
public:
    int calculate(string s) {
        stack<int> nums, signs;
        int num = 0;
        int res = 0;
        int sign = 1;
        for(char c : s) {
            if(isdigit(c)) {
                num = 10 * num + (c - '0');
            } else {
                res += sign * num;
                num = 0;
                if(c == '+')
                    sign = 1;
                else if(c == '-')
                    sign = -1;
                else if(c == '(') {
                    nums.push(res);
                    signs.push(sign);
                    res = 0;
                    sign = 1;
                } else if(c == ')') {
                    res = signs.top() * res + nums.top();
                    signs.pop();
                    nums.pop();
                }
            }
        }
        res += sign * num;
        return res;
    }
};

// class Solution {
// public:
//     int calculate(string s) {
//         int right_par;
//         return auxiliary(s, 0, s.size(), right_par);
//     }
    
//     int auxiliary(string& s, int start, int end, int& right_par) {
//         stack<int> stk;
//         int i = start;
//         int sign = 1;
//         int num = 0;
//         while(i < end) {
//             if(s[i] == ')'){
//                 right_par = i;
//                 break;
//             } else if(s[i] == '+' || s[i] == '-') {
//                 stk.push(num * sign);
//                 num = 0;
//                 sign = s[i] == '+' ? 1 : -1;
//                 ++i;
//             } else if(isdigit(s[i])) {
//                 num = 10 * num + (s[i] - '0');
//                 ++i;
//             } else if(s[i] == '(') {
//                 num = auxiliary(s, i+1, end, right_par);
//                 i = right_par + 1;
//             } else
//                 ++i;
//         }
//         stk.push(num * sign);
//         int res = 0;
//         while(!stk.empty()) {
//             res += stk.top();
//             stk.pop();
//         }
//         return res;
//     }
// };
