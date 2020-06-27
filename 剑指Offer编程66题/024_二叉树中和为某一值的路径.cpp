// 输入一颗二叉树的根节点和一个整数，
// 按字典序打印出二叉树中结点值的和为输入整数的所有路径。
// 路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。


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
    vector<vector<int> > buffer;
    vector<int> tmp;
     
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        if(!root)  return buffer;
        tmp.push_back(root->val);
        if(!(expectNumber - root->val) && !root->left && !root->right) {
            buffer.push_back(tmp);
        }
         
        FindPath(root->left, expectNumber - root->val);
        FindPath(root->right, expectNumber - root->val);
         
        if(tmp.size())  tmp.pop_back();
        return buffer;
    }
};


// =========================

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
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        vector<vector<int> > res;
        if(root==NULL) return res;
         
        int currentSum=0;
        vector<int> temp;
        FindPath1(res, root, expectNumber, temp, currentSum);
        return res;
    }
    void FindPath1(vector<vector<int> > &res,
                    TreeNode* root,
                    int expectNumber,
                   vector<int> &temp,
                   int currentSum) {
        currentSum += root->val;
        temp.push_back(root->val);
        if(Isleaf(root) && expectNumber==currentSum)  res.push_back(temp);
        if(root->left)  FindPath1(res, root->left, expectNumber, temp, currentSum);
        if(root->right)  FindPath1(res, root->right, expectNumber, temp, currentSum);
        temp.pop_back();
    }
    bool Isleaf(TreeNode* Node) {
        if(!Node->left && !Node->right) return true;
        else return false;
    }
};
