// https://leetcode-cn.com/problems/maximal-square/
// 221. 最大正方形

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/count-complete-tree-nodes/
// 222. 完全二叉树的节点个数

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/rectangle-area/
// 223. 矩形面积

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/basic-calculator/
// 224. 基本计算器

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/implement-stack-using-queues/
// 225. 用队列实现栈

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/invert-binary-tree/
// 226. 翻转二叉树

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/basic-calculator-ii/
// 227. 基本计算器 II

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/summary-ranges/
// 228. 汇总区间

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/majority-element-ii/
// 229. 求众数 II

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/kth-smallest-element-in-a-bst/
// 230. 二叉搜索树中第K小的元素

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    int _k = 0;
    
public:
    int kthSmallest(TreeNode* root, int k) {
        if (root == NULL) return -1;
        
        int result = kthSmallest(root->left, k);
        if (_k == k) return result;
        else if (++_k == k) return root->val;
        else return kthSmallest(root->right, k);
    }
};

// other method

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    int res;
public:
    int kthSmallest(TreeNode* root, int k) {
        dfs(root,k);
        return res;
    }
    
    void dfs(TreeNode* node, int &k){
        if (!node) return;
        
        dfs(node->left, k);
        if (--k == 0) {
            res = node->val;
            return;
        }
        dfs(node->right,k);
    }
};
