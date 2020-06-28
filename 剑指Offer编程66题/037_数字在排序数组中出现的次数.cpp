// 统计一个数字在排序数组中出现的次数。


class Solution {
public:
    int GetNumberOfK(vector<int> data , int k) {
        int length = data.size();
        if (!length)  return 0;
         
        int first = GetFirstOrLastK(data, k, 0, length-1, true);
        int last = GetFirstOrLastK(data, k, 0, length-1, false);
         
        if (first>-1 && last>-1) {
            return last - first + 1;
        } else {
            return 0;
        }
    }
     
    int GetFirstOrLastK(vector<int> &data, int k, int start, int end, bool isFirst) {
        if (start > end)  return -1;
         
        int length = data.size();
        int middleIndex = (start + end) >> 1;
        int middleData = data[middleIndex];
         
        if (middleData == k) {
            if (isFirst) {
                if (middleIndex>0 && data[middleIndex-1]!=k
                    || middleIndex==0) {
                    return middleIndex;
                } else {
                    end = middleIndex - 1;
                }
            } else {
                if (middleIndex<length-1 && data[middleIndex+1]!=k
                    || middleIndex==length-1) {
                    return middleIndex;
                } else {
                    start = middleIndex + 1;
                }
            }
        }
        else if (middleData < k) {
            start = middleIndex + 1;
        }
        else {
            end = middleIndex - 1;
        }
         
        return GetFirstOrLastK(data, k, start, end, isFirst);
    }
};
