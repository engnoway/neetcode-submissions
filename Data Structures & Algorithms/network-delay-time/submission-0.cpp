class Solution {
   public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);
        int time = 0;
        int mini = INT_MAX;
        for (int i = 0; i < times.size(); i++) {
            int a = times[i][0];
            int b = times[i][1];
            int c = times[i][2];
            adj[a].push_back({b, c});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> distance(n + 1, INT_MAX);
        distance[k] = 0;
        pq.push({0, k});  // dist is 0 and k is node

        while (!pq.empty()) {
            auto [currdist, node] = pq.top();
            pq.pop();
            if (currdist > distance[node]) continue;
            for (auto [nd, weight] : adj[node]) {
               int newdist = currdist + weight;
                if (newdist < distance[nd]) {
                    distance[nd] = newdist;
                    pq.push({newdist,nd});
                }
            }
        }
        for(int i=1;i<distance.size();i++){
            if(distance[i]==INT_MAX){
               return -1;
            }
             time=max(time,distance[i]);
        }
        return time ;
    }
};
