class Solution {
   public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> adj(numCourses);
        for (const auto& pre : prerequisites) {
            int course = pre[0];
            int preq = pre[1];
            adj[preq].push_back(course);
            indegree[course]++;
        }
        int i = 0;
        int completed=0;
        queue<int> q;
        while (i < numCourses) {
            if (indegree[i] == 0) {
                q.push(i);
                                    completed++;

            }
            i++;
        }

        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (auto next : adj[cur]) {
                indegree[next]--;
                if (indegree[next] == 0) {
                    q.push(next);
                    completed++;
                }
            }
        }
        return completed==numCourses;
    }
};
