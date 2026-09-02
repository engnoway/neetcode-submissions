class Solution {
   public:
    bool isPalindrome(string s) {
        string copy;
        for (auto ch : s) {
            if (isalnum(static_cast<unsigned char>(ch)))
                copy += tolower(static_cast<unsigned char>(ch));
        }
        // int j = copy.length() - 1;
        // int i = 0;
        // while (i < j) {
        //     if (copy[i] != copy[j]) return false;
        //     j--;
        //     i++;
        // }
        // return true;
         return copy==string(copy.rbegin(),copy.rend());
    }
};
