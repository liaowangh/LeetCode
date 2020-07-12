class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        if(envelopes.empty()) return 0;
        auto comp = [](const vector<int>& e1, const vector<int>& e2){
            return e1[0] < e2[0] || (e1[0] == e2[0] && e1[1] > e2[1]);
        };
        sort(envelopes.begin(), envelopes.end(), comp);
        // We sort the envelopes first by ascending width and then by descending height,
        // which ensures if envelopes[i][1] > envelopes[j][1] and i > j
        // then envelopes[i][0] > envelopes[i][1].
        // Next: find the longest increasing subsequence in (height) envelopes[:,1]
        // tall[i]: store the smallest tail of increasing subsequence with length i+1
        vector<int> tail;
        for(auto e : envelopes){
            auto iter = lower_bound(tail.begin(), tail.end(), e[1]);
            if(iter == tail.end())
                tail.push_back(e[1]);
            else if(e[1] < *iter)
                *iter = e[1];
                
        }
        return tail.size();
    }
};
