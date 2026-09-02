class Solution {
   public:
    bool isPalindrome(string s) {
        int r = s.length() - 1;
        int l = 0;
        while (l < r) {
            while (l < r && !isalnum(s[l])) l++;  // skip special characters
            while (l < r && !isalnum(s[r])) r--;  // skip special characters

            if (tolower(s[l]) != tolower(s[r])) return false;
            r--;
            l++;
        }
        return true;
        // string copy;
        // for (auto ch : s) {
        //     if (isalnum(static_cast<unsigned char>(ch)))
        //         copy += tolower(static_cast<unsigned char>(ch));
        // }
        // int j = copy.length() - 1;
        // int i = 0;
        // while (i < j) {
        //     if (copy[i] != copy[j]) return false;
        //     j--;
        //     i++;
        // }
        // return true;
        // return copy==string(copy.rbegin(),copy.rend());
    }
};
