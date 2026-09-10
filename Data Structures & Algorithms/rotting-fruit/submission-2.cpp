class Solution {
   public:
    int orangesRotting(vector<vector<int>>& grid) {
        int levels = 0;
        queue<pair<int, int>> q;

        int fresh = 0;
        int rows = grid.size();
        int cols = grid[0].size();

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (grid[row][col] == 2) {
                    q.push({row, col});
                }
                if (grid[row][col] == 1) {
                    fresh++;
                }
            }
        }
        vector<pair<int, int>> drs{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        while (!q.empty() && fresh > 0) {
            int quesize = q.size();

            while (quesize) {
                auto [cr, cc] = q.front();
                q.pop();

                for (auto [dr, dc] : drs) {
                    int nr = cr + dr;
                    int nc = cc + dc;
                    if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == 1) {
                        fresh--;
                        grid[nr][nc] = 2;
                        q.push({nr, nc});
                    }
                }
                quesize--;
            }
            levels++;
        }

        return fresh == 0 ? levels : -1;
    }
};
