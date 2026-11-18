class Solution {
   public:
    bool dfs(vector<vector<char>>& board, string word, int row, int col, int index) {
        if (index == word.length()) return true;
        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size()) return false;
        if (board[row][col] != word[index]) return false;
        char temp = board[row][col];  // save
        board[row][col] = '#';        // mark as visited
        // check right,left,up,down directions
        bool found = dfs(board, word, row + 1, col, index + 1) ||
                     dfs(board, word, row - 1, col, index + 1) ||
                     dfs(board, word, row, col + 1, index + 1) ||
                     dfs(board, word, row, col - 1, index + 1);
        // unchoose unsave
        board[row][col] = temp;
        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for (int row = 0; row < board.size(); row++) {
            for (int col = 0; col < board[0].size(); col++) {
                if (dfs(board, word, row, col, 0)) return true;
            }
        }
        return false;
    }
};
