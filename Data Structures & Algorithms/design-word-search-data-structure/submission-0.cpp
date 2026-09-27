struct TrieNode {
    unordered_map<char, TrieNode*> child;
    bool endword = false;
};
class WordDictionary {
   public:
    TrieNode* root;

    WordDictionary() { root = new TrieNode(); }

    void addWord(string word) {
        TrieNode* curr = root;
        for (auto ch : word) {
            if (curr->child.count(ch) == 0) {
                curr->child[ch] = new TrieNode();
            }
            curr = curr->child[ch];
        }
        curr->endword = true;
    }
    bool dfs(const string& word, int i, TrieNode* curr) {
        if (i == word.size()) return curr->endword;
        char ch = word[i];

        if (ch != '.') {
            if (curr->child.count(ch) == 0) {
                return false;
            }
            return dfs(word, i + 1, curr->child[ch]);
        }
        // if there is .
        for (auto& [charr, mnext] : curr->child) {
            if(dfs(word,i+1,mnext)){
            return true;
            }
        }
        return false;
    }
    bool search(string word) { return dfs(word, 0, root); }
};
