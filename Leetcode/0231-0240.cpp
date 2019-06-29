// https://leetcode-cn.com/problems/power-of-two/
// 231. 2的幂

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0 || n & (n-1))  return false;
        else  return true;
    }
};

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/implement-queue-using-stacks/
// 232. 用栈实现队列

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/number-of-digit-one/
// 233. 数字 1 的个数

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/palindrome-linked-list/
// 234. 回文链表

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head, *fast = head,  *prev = NULL;
        while (fast != NULL) {
            slow = slow->next;
            fast = fast->next != NULL ? fast->next->next : fast->next;
        }
        while (slow) {
            ListNode* ovn = slow->next;
            slow->next = prev;
            prev = slow;
            slow = ovn;
        }
        while (head && prev) { 
            if (head->val != prev->val) return false;
            head = head->next;
            prev = prev->next;
        }
        return true;
    }
};

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
// 235. 二叉搜索树的最近公共祖先

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) return NULL;
        
        if ((root->val - p->val) * (root->val - q->val) <= 0) return root;
        else if (root->val > p->val) return lowestCommonAncestor(root->left, p, q);
        else return lowestCommonAncestor(root->right, p, q);
    }
};

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/
// 236. 二叉树的最近公共祖先

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL || root == p || root == q) return root;
        
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        
        if (left != NULL && right != NULL) return root;
        else if (left != NULL) return left;
        else if (right != NULL) return right;
        else return NULL;
    }
};

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/delete-node-in-a-linked-list/
// 237. 删除链表中的节点

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/product-of-array-except-self/
// 238. 除自身以外数组的乘积

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int length = nums.size();
        
        vector<int> result(length, 1);
        
        for (int i = 0, left = 1; i < length; i++) {
            result[i] = left;
            left *= nums[i];
        }
        for (int i = length-1, right = 1; i >= 0; i--) {
            result[i] *= right;
            right *= nums[i];
        }
        
        return result;
    }
};

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/sliding-window-maximum/
// 239. 滑动窗口最大值

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/search-a-2d-matrix-ii/
// 240. 搜索二维矩阵 II

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0) return false;
        
        int i = 0;
        int j = matrix[0].size()-1;
        while (i < matrix.size() && j >= 0) {
            if (matrix[i][j] == target) return true;
            
            if (matrix[i][j] < target) ++i;
            else --j;
        }
        return false;
    }
};