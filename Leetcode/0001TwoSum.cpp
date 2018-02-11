class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        vector<int> result;

        for (int i = 0; i < nums.size(); i++) {
            int numberToFind = target - nums[i];
            if (hash.find(numberToFind) != hash.end()) {
                result.push_back(hash[numberToFind]);
                result.push_back(i);
                return result;
            }
            hash[nums[i]] = i;
        }
        return result;
    }
};

// hash.find() takes constant time
// http://www.cplusplus.com/reference/unordered_map/unordered_map/find/


// 更简洁的版本
// 没有考虑无返回值的情况，但是submit solution是可以accepted的

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> imap;

        for (int i = 0;; ++i) {
            auto it = imap.find(target - nums[i]);
            if (it != imap.end()) 
                return vector<int> {it->second, i};
            imap[nums[i]] = i;
        }
    }
};