class Solution {
   public:
    vector<string> ipstr;
    void backtrack(string& s, int index, int seg, string curr) {
        string res;
        if (seg == 4) {
            if (s.size() == index) {
                curr.pop_back();  // remove last "."
                ipstr.push_back(curr);
            }
            return;
        }
        for (int len = 1; len <= 3; len++) {
            if ((index + len) > s.size()) break;
            res = s.substr(index, len);
            if (res.size() > 1 && res[0] == '0') break;
            if (stoi(res) > 255) break;
            backtrack(s, index + len, seg + 1, curr + res + ".");
        }
    }
    vector<string> restoreIpAddresses(string s) {
        backtrack(s, 0, 0, "");
        return ipstr;
    }
};