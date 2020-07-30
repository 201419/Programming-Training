// https://leetcode-cn.com/problems/container-with-most-water/
// 11. 盛最多水的容器

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxarea = 0, left = 0, right = height.size() - 1, x = 0, area = 0;
        while (left < right) {
            x = height[left] < height[right] ? height[left] : height[right];
            area = x * (right - left);
            maxarea = maxarea > area ? maxarea : area;
            if (height[left] < height[right])  left++;
            else  right--;
        }
        return maxarea;
    }
};

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/integer-to-roman/
// 12. 整数转罗马数字

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/roman-to-integer/
// 13. 罗马数字转整数

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/longest-common-prefix/
// 14. 最长公共前缀

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 1)  return strs[0];
        if (strs.size() == 0)  return "";
        
        int i = 0, j = 0;
        string str = "";
        
        while (true) {
            i = 0;
            if (strs[i] == "")  return "";
            while(i < strs.size() - 1) {
                if (strs[i][j] != strs[i+1][j])  return str;
                i++;
            }
            if (j >= strs[0].size())  break;
            str += strs[0][j];
            j++;
        }
        
        return str;
    }
};

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/3sum/
// 15. 三数之和

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() < 3) return {};
        
        vector<vector<int>> res;
        
        sort(nums.begin(), nums.end());
        int len = nums.size();
        for (int i = 0; i < len - 2; i++) {
            int j = i + 1, k = len - 1;
            while (j < k) {
                if (nums[i] + nums[j] + nums[k] < 0) j++;
                else if (nums[i] + nums[j] + nums[k] > 0) k--;
                else {
                    vector<int> temp;
                    temp = {nums[i], nums[j++], nums[k--]};
                    res.push_back(temp);
                    while (j < k && nums[j] == nums[j-1]) j++;
                    while (j < k && nums[k] == nums[k+1]) k--;
                }
            }
            while (i < len - 2 && nums[i] == nums[i+1]) i++;
        }
        // sort(res.begin(), res.end());
        // res.erase(unique(res.begin(), res.end()), res.end());
        return res;
    }
};

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/3sum-closest/
// 16. 最接近的三数之和

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        
        int len = nums.size();
        int i = 0, j = 1, k = len - 1;
        int res = nums[i] + nums[j] + nums[k];
        
        for (; i < len - 2; i++) {
            j = i + 1, k = len - 1;
            while (j < k) {
                res = abs(res-target) < abs(nums[i]+nums[j]+nums[k]-target) ? res : nums[i]+nums[j]+nums[k];
            
                if (nums[i] + nums[j] + nums[k] > target) k--;
                else if (nums[i] + nums[j] + nums[k] < target) j++;
                else return target;
            }
        }
        return res;
    }
};

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/
// 17. 电话号码的字母组合

class Solution {
public:
    vector<string> tab={"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    vector<string> letterCombinations(string digits) {
        int len = digits.size();
        if (len == 0) return {};
        
        vector<string> res;
        string path;
        dfs(res, digits, 0, path);
        
        return res;
    }
    
    void dfs(vector<string>& res, string digits, int di, string path) {
        if (di == digits.size()) res.push_back(path);
        else {
            int num = digits[di] - '0';
            for (int ti = 0; ti < tab[num].size(); ti++) {
                path.push_back(tab[num][ti]);
                di++;
                dfs(res, digits, di, path);
                di--;
                path.pop_back();
            }
        }
    }
    
};

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/4sum/
// 18. 四数之和

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
		if (n < 4) return {};
		sort(nums.begin(), nums.end());
        
		vector<vector<int>> res;
		for (int i = 0; i < n - 3; i++) {
			if (i > 0 && nums[i] == nums[i - 1]) continue;
			if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) break;
			if (nums[i] + nums[n - 3] + nums[n - 2] + nums[n - 1] < target) continue;
 
			for (int j = i + 1; j < n - 2; j++) {
				if (j > i + 1 && nums[j] == nums[j - 1])continue;
				if (nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) break;
				if (nums[i] + nums[j] + nums[n - 2] + nums[n - 1] < target) continue;
				
				int l = j + 1, r = n - 1;
				while (l < r) {
					int sum = nums[i] + nums[j] + nums[l] + nums[r];
                    
                    if (sum < target) l++;
                    else if (sum > target) r--;
                    else {
                        res.push_back({nums[i], nums[j], nums[l++], nums[r--]});
						while (l < r && nums[l] == nums[l - 1]) l++;
						while (l < r && nums[r] == nums[r + 1]) r--;
                    }
				}
			}
		}
		return res;
    }
};

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/
// 19. 删除链表的倒数第N个节点

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        if(!head | !head -> next) return NULL;
        
        ListNode* fast = head;
        ListNode* slow = head;
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }
        if (!fast) {
            return head->next;
        }
        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return head;
    }
};

// ===============

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        if(!head | !head -> next) return NULL;
        
        vector<ListNode*> vec;
        while (head) {
            vec.push_back(head);
            head = head->next;
        }
        vec.erase(vec.begin()+vec.size()-n);
        if (vec.size() == 0)  return NULL;
        for (int i = 0 ; i < vec.size()-1 ; i++) {
            vec[i]->next = vec[i+1];
        }
        vec[vec.size()-1]->next = NULL;
        return vec[0];
    }
};

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/valid-parentheses/
// 20. 有效的括号

class Solution {
public:
    bool isValid(string s) {
        stack<char> a;
        a.push('0');
        
        for (int i = 0; i < s.size(); i++) {
            switch (s[i]) {
                case '}':
                    if (a.top() == '{')  a.pop();
                    else  return false;
                    break;
                case ')':
                    if (a.top() == '(')  a.pop();
                    else  return false;
                    break;
                case ']':
                    if (a.top() == '[')  a.pop();
                    else  return false;
                    break;
                default:
                    a.push(s[i]);
                    break;
            }
        }
        
        if (a.top() == '0')  return true;
        else  return false;
    }
};
