class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        if(numCourses == 1) return true;
        vector<vector<int>> Adj(numCourses, vector<int>());
        vector<int> indeg(numCourses);
        for(auto edge : pre){
            Adj[edge[0]].push_back(edge[1]);
            indeg[edge[1]]++;
        }
        queue<int> que;
        for(int i = 0; i < numCourses; ++i){
            if(indeg[i] == 0)
                que.push(i);
        }
        int n = numCourses;
        while(!que.empty()){
            int cur = que.front();
            que.pop();
            n--;
            for(auto i : Adj[cur]){
                if(--indeg[i] == 0)
                    que.push(i);
            }
        }
        return n == 0;
    }
    
};
// class Solution {
// public:
//     bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
//         if(numCourses == 1) return true;
//         vector<int> color(numCourses); // 0-white, 1-gray,2-black
//         vector<vector<int>> Adj(numCourses, vector<int>());
//         // build adjacency list
//         for(auto i : prerequisites)
//             Adj[i[0]].push_back(i[1]);
        
//         bool find_loop = false;
        
//         for(int i = 0; i < numCourses; ++i){
//             if(color[i] == 0){
//                 DFS(i, Adj, color, find_loop);
//                 if(find_loop) return false;
//             }
//         }
//         return true;
//     }
    
//     void DFS(int cur, vector<vector<int>>& Adj, vector<int>& color, bool& find_loop){
//         color[cur] = 1;
//         for(auto i : Adj[cur]){
//             if(find_loop) return;
//             if(color[i] == 1){
//                 // gray: back edge
//                 find_loop = true;
//                 return;  // existence of loop
//             }
//             else if(color[i] == 0){
//                 // white
//                 DFS(i, Adj, color, find_loop);
//             }
//         }
//         color[cur] = 2;
//     }
    
// };
