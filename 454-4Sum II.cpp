class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int count = 0;
        unordered_map<int, int> AB;
        for(int a : A)
            for(int b : B)
                AB[a + b]++;
        
        for(int c : C)
            for(int d: D)
                if(AB.find(-c-d) != AB.end())
                    count += AB[-c-d];
        return count;
        
    }

};
