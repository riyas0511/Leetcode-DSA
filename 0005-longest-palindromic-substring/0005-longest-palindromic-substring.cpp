class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if (n <= 1) {
            return s;
        }

        string LPS = "";

        for (int i = 1; i < n; i++) {
            // Odd-length palindrome
            int low = i, high = i;
            while ( s[low] == s[high]) {
                low--;
                high++;

                if (low == -1 || high == n)
                    break;
            }

            string palindrome = s.substr(low + 1, high - low - 1);
            if (palindrome.length() > LPS.length()) {
                LPS = palindrome;
            }

            // Even-length palindrome
            low = i - 1;
            high = i;
            while ( s[low] == s[high]) {
                low--;
                high++;

                if (low == -1 || high == n)
                    break;
            }

            palindrome = s.substr(low + 1, high - low - 1);
            if (palindrome.length() > LPS.length()) {
                LPS = palindrome;
            }
        }

        return LPS;
    }
};
