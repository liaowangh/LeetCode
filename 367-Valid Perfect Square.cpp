class Solution {
public:
    bool isPerfectSquare(int num) {
        // use newton's method to seek for solution
        if(num == 1) return true;
        int x = num / 2 + 1;
        while(x > num / x)
            x = (x + num / x) / 2;
        return x * x == num;
    }
};
