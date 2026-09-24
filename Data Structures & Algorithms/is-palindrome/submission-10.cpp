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
       
    }
};
