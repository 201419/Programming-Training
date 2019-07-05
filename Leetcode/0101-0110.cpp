// https://leetcode-cn.com/problems/symmetric-tree/
// 101. 对称二叉树

// --- 递归 ---

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
public:
    bool isSymmetric(TreeNode* root) {
        return isMirror(root, root);
    }
    
private:
    bool isMirror(TreeNode* t1, TreeNode* t2) {
        if (t1 == NULL && t2 == NULL) return true;
        if (t1 == NULL || t2 == NULL) return false;
        return (t1->val == t2->val) && isMirror(t1->right, t2->left) && isMirror(t1->left, t2->right);
    }
};

// --- 迭代 ---

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
public:
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        q.push(root);
        while (!q.empty()) {
            TreeNode* t1 = q.front();
            q.pop();
            TreeNode* t2 = q.front();
            q.pop();
            if (t1 == NULL && t2 == NULL) continue;
            if (t1 == NULL || t2 == NULL) return false;
            if (t1->val != t2->val) return false;
            q.push(t1->left);
            q.push(t2->right);
            q.push(t1->right);
            q.push(t2->left);
        }
        return true;
    }
};

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/binary-tree-level-order-traversal/
// 102. 二叉树的层次遍历

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal/
// 103. 二叉树的锯齿形层次遍历

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/
// 104. 二叉树的最大深度

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
public:
    int maxDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        } else {
            int left_height = maxDepth(root->left);
            int right_height = maxDepth(root->right);
            return (left_height > right_height ? left_height : right_height) + 1;
        }
    }
};

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
// 105. 从前序与中序遍历序列构造二叉树

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
// 106. 从中序与后序遍历序列构造二叉树

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii/
// 107. 二叉树的层次遍历 II

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/convert-sorted-array-to-binary-search-tree/
// 108. 将有序数组转换为二叉搜索树

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/convert-sorted-list-to-binary-search-tree/
// 109. 有序链表转换二叉搜索树

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/balanced-binary-tree/
// 110. 平衡二叉树
