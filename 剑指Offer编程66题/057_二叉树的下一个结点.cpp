// 给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。
// 注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针。


/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
         
    }
};
*/
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode) {
        if (NULL == pNode) return NULL;
         
        TreeLinkNode* pNext = NULL;
        if (pNode->right != NULL) {
            TreeLinkNode* pRight = pNode->right;
            while(pRight->left != NULL) pRight = pRight->left;
            pNext = pRight;
        } else if(pNode->next != NULL){
            TreeLinkNode* pParent = pNode->next;
            TreeLinkNode* pCurrent = pNode;
            while(NULL != pParent && pCurrent == pParent->right){
                pCurrent = pParent; pParent = pParent->next;
            }
            pNext = pParent;
        }
        return pNext;
    }
};
