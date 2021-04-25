class Solution {
public:
    // Topological sort using BSF
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> g(numCourses);
        // g[i][j] = 1 means you have to take course i before taking course j
        vector<int> indeg(numCourses);
        for(auto edge : prerequisites) {
            g[edge[1]].push_back(edge[0]);
            indeg[edge[0]]++;
        }
        vector<int> res;
        queue<int> que;
        for(int i = 0; i < numCourses; ++i){
            if(indeg[i] == 0)
                que.push(i);
        }
        int count = numCourses;
        while(!que.empty()) {
            int cur = que.front();
            res.push_back(cur);
            que.pop();
            count--;
            for(int j : g[cur]){
                if(--indeg[j] == 0)
                    que.push(j);
            }
        }
        return count ? vector<int>() : res;
    }
};
