class Solution {
   public:
    void bfs(vector<vector<char>>& grid, int row, int col) {
        queue<pair<int, int>> q;

        q.push({row, col});

        grid[row][col] = '0';  // mark it as visited
        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            vector<pair<int, int>> dirs{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
            int rows = grid.size();
            int cols = grid[row].size();

            for (auto [dr, dc] : dirs) {
                int newr = dr + r;
                int newc = dc + c;
                if (newr >= 0 && newr < rows && newc >= 0 && newc < cols &&
                    grid[newr][newc] == '1') {  // within the range
                    q.push({newr, newc});
                    grid[newr][newc] = '0';
                }
    
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int island = 0;
        for (int row = 0; row < grid.size(); row++) {
            for (int col = 0; col < grid[row].size(); col++) {
                if (grid[row][col] == '1') {
                    island++;
                    // Build BFS
                    bfs(grid, row, col);
                }
            }
        }
        return island;
    }
};
