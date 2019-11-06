class Solution {
public:
    // extend palindrome, 4ms, 8.6MB
    int countSubstrings(string s) {
        int n = s.size();
        if(n <= 1) return n;
        int count = 0;
        for(int i = 0; i < n; ++i){
            extendPalindrome(s, i, i, count);
            extendPalindrome(s, i, i + 1, count);
        }
        return count;
    }
    
    void extendPalindrome(const string& s, int left, int right, int& count){
        while(left >= 0 && right < s.size() && s[left] == s[right]){
            count++;
            left--;
            right++;
        }
    }
    
    // 8ms, 8.7MB
    // int countSubstrings(string s) {
    //     int n = s.size();
    //     if(n <= 1) return n;
    //     int count = 1;
    //     vector<int> start(n,0);
    //     start[0] = 1;
    //     for(int i = 1; i < n; ++i){
    //         count++; // a single char is a palindromic.
    //         // s[j]-s[i-1] is palindromic if start[j] == 1
    //         // we want to know whether s[j-1]-s[i] is palindromic
    //         start[i] = 1;
    //         for(int j = 1; j <= i; ++j){
    //             if(start[j] == 1){
    //                 start[j] = 0;
    //                 if(s[j-1] == s[i]){
    //                     count++;
    //                     start[j-1] = 1;
    //                 }
    //             }
    //         }
    //         start[i] = 1;
    //     }
    //     return count;
    // }
    
    // 20 ms, 20.4MB
    // int countSubstrings(string s) {
    //     int n = s.size();
    //     if(n <= 1) return n;
    //     int count = 1;
    //     stack<int> start;
    //     start.push(0);
    //     for(int i = 1; i < n; ++i){
    //         count++; // a single char is a palindromic.
    //         // s[start[j]]-s[i-1] is palindromic
    //         stack<int> tmp;
    //         tmp.push(i);
    //         if(s[i] == s[i-1]){
    //             count++;
    //             tmp.push(i-1);
    //         }
    //         while(!start.empty()){
    //             int k = start.top();
    //             // we need to check whether s[k-1] - s[i] is palindromic
    //             if(k > 0 && s[k-1] == s[i]){
    //                 tmp.push(k-1);
    //                 count++;
    //             }
    //             start.pop();
    //         }
    //         start = tmp;
    //     }
    //     return count;
    // }
};
