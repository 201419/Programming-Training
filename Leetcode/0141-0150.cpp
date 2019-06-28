// https://leetcode-cn.com/problems/linked-list-cycle/
// 141. 环形链表

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
    bool hasCycle(ListNode *head) {
        if (head == NULL || head->next == NULL)  return false;
        ListNode *slow = head;
        ListNode *fast = head->next;
        while (slow != fast) {
            if (fast == NULL || fast->next == NULL)  return false;
            slow = slow->next;
            fast = fast->next->next;
        }
        return true;
    }
};

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/linked-list-cycle-ii/
// 142. 环形链表 II

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
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL) return NULL;
        
        ListNode *p1 = head, *p2 = head;
        int isCycle = 0;
        while (p2->next != NULL && p2->next->next != NULL) {
            p1 = p1->next;
            p2 = p2->next->next;
            if (p1 == p2) {
                isCycle = 1;
                break;
            }
        }
        
        if (isCycle == 1) {
            ListNode *p3 = head;
            while (p3 != p1) {
                p3 = p3->next;
                p1 = p1->next;
            }
            return p3;
        } else {
            return NULL;
        }
    }
};

// ---------------------------------------------------------------------------


// ---------------------------------------------------------------------------


// ---------------------------------------------------------------------------


// ---------------------------------------------------------------------------



// ---------------------------------------------------------------------------


// ---------------------------------------------------------------------------


// ---------------------------------------------------------------------------


// ---------------------------------------------------------------------------
