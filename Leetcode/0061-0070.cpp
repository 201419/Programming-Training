// https://leetcode-cn.com/problems/rotate-list/
// 61. 旋转链表

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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL) return NULL;
        
        ListNode *p1 = head;
        while (p1->next != NULL) {
            p1 = p1->next;
        }
        p1->next = head;
        
        p1 = head;
        while (k--) {
            p1 = p1->next;
        }
        
        ListNode *p2 = head;
        while (p1->next != head) {
            p1 = p1->next;
            p2 = p2->next;
        }
        ListNode *ret = p2->next;
        p2->next = NULL;
        return ret;
    }
};

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/unique-paths/
// 62. 不同路径

class Solution {
public:
    int uniquePaths(int m, int n) {
        int step = m + n - 2;
        int minMN = m < n ? m-1 : n-1;
        
        long result = 1;
        for (int i = 0; i < minMN; i++) {
            result = result * (step-i) / (i+1);
        }
        return result;
    }
};

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/plus-one/
// 66. 加一



// ---------------------------------------------------------------------------


// ---------------------------------------------------------------------------


// ---------------------------------------------------------------------------


// ---------------------------------------------------------------------------


// ---------------------------------------------------------------------------


// ---------------------------------------------------------------------------
