class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        if(points.size() <= 2) return points.size();
        int n = points.size();
        int res = 0;
        for(int i = 0; i < n; ++i) {
            unordered_map<string, int> slopes;
            int dup = 1;
            for(int j = i+1; j < n; ++j) {
                int dy = points[j][1] - points[i][1];
                int dx = points[j][0] - points[i][0];
                int g = gcd(dy, dx);
                if(dy == 0 && dx == 0){
                    dup++;
                } else{
                    slopes[to_string(dy/g)+"_"+to_string(dx/g)]++;
                }
            }
            res = max(res, dup);
            for(auto s : slopes)
                res = max(res, s.second + dup);
        }
        return res;
    }
    
    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
};

// class Solution {
// public:
//     int maxPoints(vector<vector<int>>& points) {
//         if(points.size() <= 2) return points.size();
//         int n = points.size();
//         int res = 0;
//         for(int i = 0; i < n - 1; ++i){
//             // For a starting point
//             long long int x0 = points[i][0];
//             long long int y0 = points[i][1];
//             for(int j = 1; j < n; ++j){
//                 // Starting point and the this point determine a direction
//                 long long int x1 = points[j][0];
//                 long long int y1 = points[j][1];
//                 if(x0 == x1 && y0 == y1) continue;
//                 int tmp = 0;
//                 for(int k = 0; k < n; ++k){
//                     // count the points fall in the line determined by the starting point
//                     // and the direction
//                     int x2 = points[k][0];
//                     int y2 = points[k][1];
//                     long long int a = (x1-x0)*(y2-y0);
//                     long long int b = (x2-x0)*(y1-y0);
//                     if(a == b)
//                         tmp++;
//                 }
//                 res = max(res, tmp);
//             }
//         }
//         // if res remains 0, then it means all points are same
//         return res ? res : points.size();
        
//     }
// };