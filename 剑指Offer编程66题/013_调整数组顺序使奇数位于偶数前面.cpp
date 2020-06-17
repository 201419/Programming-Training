class Solution {
public:
    void reOrderArray(vector<int> &array) {
        vector<int>::iterator it = array.begin();
        int size = array.size();
        while(size--) {
            if(*it%2==0) {  // !(*it&1)
                int tmp=*it;
                it=array.erase(it);
                array.push_back(tmp);
            }
            else it++;
        }
    }
};
