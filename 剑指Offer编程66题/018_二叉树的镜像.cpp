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
    void Mirror(TreeNode *pRoot) {
        if(pRoot==NULL) return;
        /* 递归实现
        TreeNode* tmp;
        tmp = pRoot->left;
        pRoot->left = pRoot->right;
        pRoot->right = tmp;
        Mirror(pRoot->left);
        Mirror(pRoot->right);
        */
        // 非递归实现
        queue<TreeNode*> qTreeNode;
        TreeNode* p = NULL;
        TreeNode* tmp;
        qTreeNode.push(pRoot);
        while(qTreeNode.size()) {
            p = qTreeNode.front();
            qTreeNode.pop();
            tmp = p->left;
            p->left = p->right;
            p->right = tmp;
            if(p->left) qTreeNode.push(p->left);
            if(p->right) qTreeNode.push(p->right);
        }
    }
};