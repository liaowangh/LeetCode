class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for(int i : nums) freq[i]++;
        vector<vector<int>> freqCount(nums.size() + 1);
        for(auto i : freq)
            freqCount[i.second].push_back(i.first);
        vector<int> res;
        int i = freqCount.size() - 1;
        while(i >= 0 && res.size() < k){
            for(int j : freqCount[i]){
                res.push_back(j);
                if(res.size() == k)
                    break;
            }
            --i;
        }
        return res;
    }
    // vector<int> topKFrequent(vector<int>& nums, int k) {
    //     using mapIter = unordered_map<int, int>::iterator;
    //     unordered_map<int, int> freq;
    //     for(int i : nums) freq[i]++;
    //     priority_queue<mapIter, vector<mapIter>, function<bool(mapIter, mapIter)>>
    //         topkHeap(
    //         [](mapIter p, mapIter q){
    //             return p->second > q->second;
    //         },
    //         vector<mapIter>()
    //     );
    //     for(mapIter i = freq.begin(); i != freq.end(); ++i){
    //         topkHeap.push(i);
    //         if(topkHeap.size() > k)
    //             topkHeap.pop();
    //     }
    //     vector<int> res;
    //     for(int i = k; i > 0; --i){
    //         res.push_back(topkHeap.top()->first);
    //         topkHeap.pop();
    //     }
    //     return res;
    // }
};
