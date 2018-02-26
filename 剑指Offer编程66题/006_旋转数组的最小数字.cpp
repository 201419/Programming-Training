class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        int size=rotateArray.size();
        if (size==0) return 0;
        int low=0, high=size-1, mid;
        while(low<high) {
            if(rotateArray[low]<rotateArray[high]) break;
            else {
                mid = (low+high)/2;
                if(rotateArray[low]<=rotateArray[mid]) low=mid+1;
                else high=mid;
            }
        }
        return rotateArray[low];
    }
};