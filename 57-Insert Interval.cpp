class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval){
        vector<vector<int>> res;
        int i = 0, n = intervals.size();
        while(i < n && intervals[i][1] < newInterval[0])
            res.push_back(intervals[i++]);
        // merge the newInterval with the intervals it intersects with
        while(i < n && intervals[i][0] <= newInterval[1]){
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            ++i;
        }
        res.push_back(newInterval);
        while(i < n)
            res.push_back(intervals[i++]);
        return res;
    }
};

// class Solution {
// public:
//     vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
//         vector<vector<int>> res;
//         int n = intervals.size();
//         if(n == 0){
//             res.push_back(newInterval);
//             return res;
//         };
//         if(newInterval[1] < intervals[0][0]){
//             res.push_back(newInterval);
//             for(auto i : intervals) res.push_back(i);
//             return res;
//         }
//         if(newInterval[0] > intervals[n-1][1]){
//             res = intervals;
//             res.push_back(newInterval);
//             return res;
//         }
//         bool inserted = false;
//         for(int i = 0; i < n; ++i){
//             if(intervals[i][1] < newInterval[0]){
//                 res.push_back(intervals[i]);
//                 continue;
//             }
            
//             if(inserted){
//                 vector<int> last_res = res.back();
//                 if(last_res[1] < intervals[i][0])
//                     res.push_back(intervals[i]);
//                 else
//                     res.back()[1] = max(res.back()[1], intervals[i][1]);
//                 continue;
//             }
            
//             if(intervals[i][0] <= newInterval[0]){
//                 res.push_back(vector<int>{intervals[i][0],
//                                           max(intervals[i][1], newInterval[1])});
//             } else if(intervals[i][0] >= newInterval[0] &&
//                       intervals[i][1] <= newInterval[1]){
//                 res.push_back(newInterval);
//             } else if(intervals[i][0] <= newInterval[1]){
//                 res.push_back(vector<int>{newInterval[0], intervals[i][1]});
//             } else{
//                 res.push_back(newInterval);
//                 res.push_back(intervals[i]);
//             }
//             inserted = true;
//         }
//         return res;
//     }
// };
