// 从上往下打印出二叉树的每个节点，同层节点从左至右打印。


/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/
class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> que;
        if(!root) return que;
         
        TreeNode* pNode;
        queue<TreeNode*> dequeTreeNode;
         
        dequeTreeNode.push(root);
        while(!dequeTreeNode.empty()) {
            pNode = dequeTreeNode.front();
            que.push_back(pNode->val);
            if(pNode->left) dequeTreeNode.push(pNode->left);
            if(pNode->right) dequeTreeNode.push(pNode->right);
            dequeTreeNode.pop();
        }
  
       return que;
    }
};