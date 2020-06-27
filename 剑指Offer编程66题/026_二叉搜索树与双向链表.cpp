// 输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。
// 要求不能创建任何新的结点，只能调整树中结点指针的指向。


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
    TreeNode* Convert(TreeNode* pRootOfTree) {
        if (!pRootOfTree)  return NULL;
        TreeNode *pointer = NULL;
        convert2List(pRootOfTree, pointer);
        while (pointer->left) { pointer = pointer->left; }
        return pointer;
    }
     
    // https://blog.csdn.net/feng_shaoxia/article/details/89704727
    // 指针的引用
    void convert2List(TreeNode* pRoot,TreeNode *&pointer) {
        if (!pRoot)  return;
        if (pRoot->left)  convert2List(pRoot->left, pointer);
         
        pRoot->left = pointer;
        if (pointer)  pointer->right = pRoot;
         
        pointer = pRoot;
        if (pRoot->right)  convert2List(pRoot->right, pointer);
    }
};