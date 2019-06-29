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


// ---------------------------------------------------------------------------


// ---------------------------------------------------------------------------


// ---------------------------------------------------------------------------


// ---------------------------------------------------------------------------
