class Solution {
public:
    string decodeString(string s) {
        int i = 0;
        return helper(s, i);
    }
    
    string helper(string s, int& i){
        string res;
        while(i < s.size() && s[i] != ']'){
            if(!isdigit(s[i]))
                res += s[i++];
            else{
                int n = 0;
                while(i < s.size() && isdigit(s[i]))
                    n = n*10 + s[i++] - '0';
                // now s[i] == '['
                i++; // skip '['
                string tmp = helper(s, i);
                i++; // skip ']'
                while(n--)
                    res += tmp;
            }
        }
        return res;
    }
//     string decodeString(string s) {
//         string res;
//         if(s.empty()) return res;
//         int end;
//         int repeat = 0;
//         for(int i = 0; i < s.size(); ++i){
//             if(s[i] >= '0' && s[i] <= '9' && s[i+1] != '[')
//                 repeat = repeat * 10 + s[i] - '0';
//             else if (s[i] >= '0' && s[i] <= '9' && s[i+1] == '['){
//                 repeat = repeat * 10 + s[i] - '0';
//                 string tmp = helper(s, i + 1, end);
//                 for(int j = 0; j < repeat; ++j)
//                     res += tmp;
//                 i = end;
//                 repeat = 0;
//             } else
//                 res += s[i];
//         }
//         return res;
//     }
    
//     string helper(string s, int start, int & end){
//         // s[start] == '[', return the string after decoding in []
//         // and end store the index of ']' corresponds to s[start] in end.
//         string res;
//         int repeat = 0;
//         for(int i = start + 1; i < s.size(); ++i){
//             if(s[i] == ']'){
//                 end = i;
//                 break;
//             } else if(s[i] >= '0' && s[i] <= '9' && s[i+1] != '[')
//                 repeat = repeat * 10 + s[i] - '0';
//             else if(s[i] >= '0' && s[i] <= '9' && s[i+1] == '['){
//                 repeat = repeat * 10 + s[i] - '0';
//                 int end_tmp;
//                 string tmp = helper(s, i + 1, end_tmp);
//                 for(int j = 0; j < repeat; ++j)
//                     res += tmp;
//                 i = end_tmp;
//                 repeat = 0;
//             } else
//                 res += s[i];
//         }
//         return res;
//     }
};
