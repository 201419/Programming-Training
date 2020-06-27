// 输入n个整数，找出其中最小的K个数。
// 例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,。


class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        int length = input.size();
        vector<int> res;
        if (k<1 || length<k)  return res;
         
        multiset<int, greater<int>> leastNumbers;
        multiset<int, greater<int>>::iterator iterGreatest;
        vector<int>::const_iterator iter = input.begin();
        for (; iter!=input.end(); iter++) {
            if (leastNumbers.size() < k) {
                leastNumbers.insert(*iter);
            }
            else {
                iterGreatest = leastNumbers.begin();
                if (*iter < *(leastNumbers.begin())) {
                    leastNumbers.erase(iterGreatest);
                    leastNumbers.insert(*iter);
                }
            }
        }
        while (leastNumbers.size()) {
            iterGreatest = leastNumbers.begin();
            res.push_back(*iterGreatest);
            leastNumbers.erase(iterGreatest);
        }
        return res;
    }
};