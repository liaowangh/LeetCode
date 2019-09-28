class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start = 0;
        int tank = 0;
        int total = 0;
        for(int i = 0; i < gas.size(); ++i){
            tank += gas[i] - cost[i];
            if(tank < 0){
                start = i + 1;
                total += tank;
                tank = 0;
            }
        }
        return (tank + total < 0) ? -1 : start;
    }
    
    // brute force, too slow
    // int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    //     int left;
    //     for(int i = 0; i < gas.size(); ++i){
    //         left = 0;
    //         for(int j = i; j < i + gas.size(); ++j){
    //             if(left < 0) break;
    //             int k = j % gas.size();
    //             left += gas[k] - cost[k];
    //         }
    //         if(left >= 0) return i;
    //     }
    //     return -1;
    // }
};
