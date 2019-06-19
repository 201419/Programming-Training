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

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/
// 17. 电话号码的字母组合

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/4sum/
// 18. 四数之和

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/
// 19. 删除链表的倒数第N个节点

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/valid-parentheses/
// 20. 有效的括号

