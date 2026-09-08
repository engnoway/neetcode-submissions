class Solution {
   public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> merged;
        vector<int> curr;
        sort(intervals.begin(), intervals.end());
        curr = intervals[0];
        for (int i = 1; i < intervals.size(); i++) {
            int currend = curr[1];
            int nextstart = intervals[i][0];
            int nextend = intervals[i][1];

            if (currend >= nextstart)  // ovelap
            {
                curr[1] = max(currend, nextend);
            } else {  // nooverlap
                merged.push_back(curr);
                curr = intervals[i];
            }
        }
        merged.push_back(curr);

        return merged;
    }
};
