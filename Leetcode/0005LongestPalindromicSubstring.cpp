class Solution {
public:
    string longestPalindrome(string s) {
        const int n = s.size();
        
        if (n == 0) return "";
        if (n == 1) return s;
        
        int start = 0, maxlen = 1;
        for (int i = 0; i < n;) {
            if (n - i <= maxlen / 2) break;
            int j = i, k = i + 1;
            while (k < n && s[i] == s[k]) ++k; // Skip duplicate characters.
            i = k;
            while (k < n && j > 0 && s[k] == s[j - 1]) { ++k; --j; } // Expand.
            int newlen = k - j;
            if (newlen >= maxlen) { start = j; maxlen = newlen; }
        }
        return s.substr(start, maxlen);
    }
};