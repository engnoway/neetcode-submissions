class Solution {
   public:

    bool dfs(int node,
             vector<vector<int>>& adj,
             vector<bool>& visit,
             vector<bool>& visiting
             ) {

        // Cycle found
        if (visiting[node])
            return false;

        // Already fully processed
        if (visit[node])
            return true;

        visiting[node] = true;

        for (int neighbor : adj[node]) {
            if (!dfs(neighbor, adj, visit, visiting))
                return false;
        }

        visiting[node] = false;
        visit[node] = true;

        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
       // vector<int> indegree(numCourses, 0);
        vector<vector<int>> adj(numCourses);

         for (const auto& pre : prerequisites) {
            int course = pre[0];
            int preq = pre[1];
            adj[preq].push_back(course);
        }
        vector<bool> visit(numCourses + 1, false);
        vector<bool> visiting(numCourses + 1, false);

        for (int i = 0; i < numCourses; i++) {

            if (!dfs(i, adj, visit, visiting)) {
                return {}; // cycle exists
            }
        }
        return true;

        //reverse(topSort.begin(), topSort.end());

        // for (const auto& pre : prerequisites) {
        //     int course = pre[0];
        //     int preq = pre[1];
        //     adj[preq].push_back(course);
        //     indegree[course]++;
        // }
        // int completed = 0;
        // queue<int> q;
        // for(int i=0;i<numCourses;i++) {
        //     if (indegree[i] == 0) {
        //         q.push(i);
        //         completed++;
        //     }
        // }

        // while (!q.empty()) {
        //     int cur = q.front();
        //     q.pop();
        //     for (auto next : adj[cur]) {
        //         indegree[next]--;
        //         if (indegree[next] == 0) {
        //             q.push(next);
        //             completed++;
        //         }
        //     }
        // }
        // return completed == numCourses;
    }
};
