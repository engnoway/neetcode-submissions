class Solution {
   public:
    bool hasCycle(int node, vector<vector<int>>& graph, vector<bool>& visited, vector<bool>& inPath,
                  vector<int>& out) {
        visited[node] = true;
        inPath[node] = true;
        for (auto neighbor : graph[node]) {
            if (!visited[neighbor]) {
                if (hasCycle(neighbor, graph, visited, inPath,out))
                    return true;  // if the cycle in the neighbor itself;
            }
            if (inPath[neighbor]) return true;  // cycle
        }
        inPath[node] = false;
        out.push_back(node);

        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<bool> visited(numCourses, false);
        vector<bool> inPath(numCourses, false);
        vector<int> out;
        for (auto& pre : prerequisites) {
            int course = pre[0];

            int prereq = pre[1];

            graph[prereq].push_back(course);
        }
        for (int curs = 0; curs < numCourses; curs++) {
            if (!visited[curs])
                if (hasCycle(curs, graph, visited, inPath, out)) return {};
        }
        reverse(out.begin(),out.end());
        return out;
    }
};
