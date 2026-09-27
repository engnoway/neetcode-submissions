struct TrieNode {
    unordered_map<char, TrieNode*> child;
    string word;
};
class Solution {
   public:
    TrieNode* root;
    Solution() { root = new TrieNode(); }
    void insertword(string word) {
        TrieNode* curr = root;
        for (auto ch : word) {
            if (curr->child.count(ch) == 0) {
                curr->child[ch] = new TrieNode();
            }
            curr = curr->child[ch];
        }
        curr->word = word;
    }

    void dfs(vector<vector<char>>& board, int ro, int col, TrieNode* curr, vector<string>& res) {
        if (ro < 0 || ro >= board.size() || col < 0 || col >= board[0].size()) {
            return;
        }
        if (board[ro][col] == '#') return;  // used that path before

        char ch = board[ro][col];

        if (curr->child.count(ch) == 0) {
            return;
        }
        curr = curr->child[ch];
        if (!curr->word.empty()) {
            res.push_back(curr->word);
            curr->word = "";  // to avoid adding the same word fom diff paths
        }
        board[ro][col]='#';
        dfs(board, ro + 1, col, curr, res);
        dfs(board, ro - 1, col, curr, res);
        dfs(board, ro, col + 1, curr, res);
        dfs(board, ro, col - 1, curr, res);
        board[ro][col] = ch;  // backtrack
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> result;
        for (auto str : words) {
            insertword(str);  // build trie
        }
        for (int row = 0; row < board.size(); row++) {
            for (int col = 0; col < board[0].size(); col++) {
                dfs(board, row, col, root, result);
            }
        }
        return result;
    }
};
