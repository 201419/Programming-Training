class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int row = array.size();
        if(row==0)
            return false;
        int col = array[0].size();
        int i = 0, j = col - 1;
        
        while(i<row && j>=0){
            if(target==array[i][j])
                return true;
            else if(target>array[i][j])
                i++;
            else j--;
        }
        return false;
    }
};