class Solution {
public:
    // 4 ms, 9.8MB
    vector<string> fizzBuzz(int n) {
        vector<string> res(n);
        for(int i = 1; i <= n; ++i)
            res[i-1] = to_string(i);
        for(int i = 2; i < n; i += 3)
            res[i] = "Fizz";
        for(int i = 4; i < n; i += 5)
            res[i] = "Buzz";
        for(int i = 14; i < n; i += 15)
            res[i] = "FizzBuzz";
        return res;
    }
    
    // too ugly  0ms, 10.5MB
    // vector<string> fizzBuzz(int n) {
    //     vector<string> res;
    //     if(n == 0) return res;
    //     for(int i = 1; i <= n; ++i){
    //         if(i % 3 == 0 and i % 5 != 0)
    //             res.push_back("Fizz");
    //         else if(i % 3 != 0 and i % 5 == 0)
    //             res.push_back("Buzz");
    //         else if (i % 3 == 0 and i % 5 == 0)
    //             res.push_back("FizzBuzz");
    //         else{
    //             res.push_back(to_string(i));
    //         }
    //     }
    //     return res;
    // }
};
