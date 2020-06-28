// 输入一棵二叉树，判断该二叉树是否是平衡二叉树。
// 在这里，我们只需要考虑其平衡性，不需要考虑其是不是排序二叉树


class Solution {
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
        if (!pRoot) return true;
        int depth = 0;
        return IsBalanced(pRoot, depth);
    }
     
    bool IsBalanced(TreeNode* pRoot, int &depth) {
        if (!pRoot) {
            depth = 0;
            return true;
        }
         
        int leftDepth, rightDepth;
        if (IsBalanced(pRoot->left, leftDepth)
            && IsBalanced(pRoot->right, rightDepth)) {
            int diff = leftDepth - rightDepth;
            if (abs(diff) <= 1) {
                depth = ((leftDepth>rightDepth) ? (leftDepth+1) : (rightDepth+1));
                return true;
            }
        }
        return false;
    }
};
