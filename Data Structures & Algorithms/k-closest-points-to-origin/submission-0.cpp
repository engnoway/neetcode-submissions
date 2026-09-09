class Solution {
   public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> out;
        vector<pair<int,vector<int>>>vect;

        int mini = INT_MAX;
        for (int i = 0; i < points.size(); i++) {
            int x = points[i][0];
            int y = points[i][1];

            int dist = x * x + y * y;
            vect.push_back({dist,{x,y}});

        
        }
        sort(vect.begin(),vect.end());
        while(k>0){
            out.push_back(vect[k-1].second);
            k--;
        }
        return out;
    }

  
}
;
