class Solution {
public:
    bool isHappy(int n) {
        int slow = n;
        int fast = n;
        do{
            slow = digitSquare(slow);
            fast = digitSquare(fast);
            if(fast == 1) return true;
            fast = digitSquare(fast);
            if(fast == 1) return true;
        } while(slow != fast);
        return fast == 1;
    }
    
    int digitSquare(int n){
        int sum = 0;
        while(n){
            int tmp = n % 10;
            sum += tmp * tmp;
            n /= 10;
        }
        return sum;
    }
};
