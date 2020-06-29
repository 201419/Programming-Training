// 从上到下按层打印二叉树，同一层结点从左至右输出。每一层输出一行。


/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
        vector<vector<int> > Print(TreeNode* pRoot) {
            vector<vector<int> > ans;
            if(pRoot == NULL) return ans;
             
            queue<TreeNode*> q;
            q.push(pRoot);
            while (!q.empty()) {
                int size = q.size();
                vector<int> levelElem;
                while (size--) {
                    TreeNode* pNode = q.front();
                    q.pop();
                    levelElem.push_back(pNode->val);
                    if(pNode->left != NULL) q.push(pNode->left);
                    if(pNode->right != NULL) q.push(pNode->right);
                }
                ans.push_back(levelElem);
            }
            return ans;
        }
     
};
