// https://leetcode-cn.com/problems/different-ways-to-add-parentheses/
// 241. 为运算表达式设计优先级

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> result;
        
        for (size_t i = 1; i < input.size() - 1 ; i++) {
            if (input[i] == '+' || input[i] == '-' || input[i] == '*') {
                
                vector<int> result1 = diffWaysToCompute(input.substr(0, i));
                vector<int> result2 = diffWaysToCompute(input.substr(i + 1));
                
                for (size_t r1 = 0; r1 < result1.size(); r1++) {
                    for (size_t r2 = 0; r2 < result2.size(); r2++) {
                        if (input[i] == '+') { result.push_back(result1[r1] + result2[r2]); }
                        else if (input[i] == '-') { result.push_back(result1[r1] - result2[r2]); }
                        else { result.push_back(result1[r1] * result2[r2]); }
                    }
                }
                
            }
        }
        
        if (result.empty() && !input.empty()){ result.push_back(stoi(input)); }
        
        return result;
    }
};

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/valid-anagram/
// 242. 有效的字母异位词

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        
        vector<int> num(26, 0);
        for (int i = 0; i < s.length(); i++) {
            num[s[i]-'a']++;
            num[t[i]-'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (num[i] != 0) return false;
        }
            
        return true;
    }
};

// ---------------------------------------------------------------------------


// ---------------------------------------------------------------------------


// ---------------------------------------------------------------------------


// ---------------------------------------------------------------------------



// ---------------------------------------------------------------------------


// ---------------------------------------------------------------------------


// ---------------------------------------------------------------------------


// ---------------------------------------------------------------------------


