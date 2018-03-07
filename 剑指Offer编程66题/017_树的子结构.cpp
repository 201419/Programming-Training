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
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2) {
        if(pRoot1==NULL||pRoot2==NULL) return false;
        return isSubtree(pRoot1, pRoot2)||HasSubtree(pRoot1->left, pRoot2)||HasSubtree(pRoot1->right, pRoot2);
    }
private:
    bool isSubtree(TreeNode* p1, TreeNode* p2) {
        if(p2==NULL) return true;
        if(p1==NULL) return false;
        if(p1->val == p2->val) return isSubtree(p1->left, p2->left)&&isSubtree(p1->right, p2->right);
        else return false;
    }
};