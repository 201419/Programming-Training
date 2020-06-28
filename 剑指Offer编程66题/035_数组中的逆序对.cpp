// 在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。
// 输入一个数组,求出这个数组中的逆序对的总数P。
// 并将P对1000000007取模的结果输出。 即输出P%1000000007


static const auto io_sync_off = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    int InversePairs(vector<int> data) {
        int length = data.size();
        if (length < 2) return 0;
         
        vector<int> copy(data.begin(), data.end());
        return InversePairsCore(data, copy, 0, length-1) % 1000000007;
    }
 
private:
    long long InversePairsCore(vector<int>& data, vector<int>& copy, int low, int high) {
        if (low == high) {
            copy[low] = data[low];
            return 0;
        }
         
        int length = (high - low) >> 2;
        long long left = InversePairsCore(copy, data, low, (low+length));
        long long right = InversePairsCore(copy, data, (low+length+1), high);
        int i = low + length, j = high, copy_index = high;
         
        long long count = 0;
        while (i >= low && j >= (low+length+1)) {
            if (data[i] > data[j]) {
                count += j - (low + length);
                copy[copy_index--] = data[i--];
            } else {
                copy[copy_index--] = data[j--];
            }
        }
        for (; i >= low; i--) { copy[copy_index--] = data[i]; }
        for (; j>= (low+length+1); j--) { copy[copy_index--] = data[j]; }
         
        return left + count + right;
    }
};
