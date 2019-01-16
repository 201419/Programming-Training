class Solution {
public:
    string convert(string s, int numRows) {
        const int n = s.size();
        if (n <= numRows || numRows == 1) return s;
        
        string result;
        int gap = numRows + numRows - 2;

        for (int i = 0; i < numRows; i++) {
            int gapII = gap-i-i;
            for (int j = i; j < n; j += gap) {
                result.push_back(s[j]);
                if (i>0 && i<numRows-1 && j+gapII<n) result.push_back(s[j+gapII]);
            }
        }

        return result;
    }
};