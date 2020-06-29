// 请实现一个函数按照之字形打印二叉树，
// 即第一行按照从左到右的顺序打印，第二层按照从右至左的顺序打印，
// 第三行按照从左到右的顺序打印，其他行以此类推。


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
 
        stack<TreeNode*> stackOne, stackTwo;
        stackOne.push(pRoot);
        while (!stackOne.empty()) {
            vector<int> levelElem;
            while (!stackOne.empty()) {
                TreeNode* pNode = stackOne.top();
                stackOne.pop();
                levelElem.push_back(pNode->val);
                if(pNode->left != NULL) stackTwo.push(pNode->left);
                if(pNode->right != NULL) stackTwo.push(pNode->right);
            }
            ans.push_back(levelElem);
            levelElem.clear();
            while (!stackTwo.empty()) {
                TreeNode* pNode = stackTwo.top();
                stackTwo.pop();
                levelElem.push_back(pNode->val);
                if(pNode->right != NULL) stackOne.push(pNode->right);
                if(pNode->left != NULL) stackOne.push(pNode->left);
            }
            if (!levelElem.empty()) {
                ans.push_back(levelElem);
                levelElem.clear();
            }
        }
        return ans;
    }
     
};
