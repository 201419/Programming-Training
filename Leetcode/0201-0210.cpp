

// ---------------------------------------------------------------------------


// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/remove-linked-list-elements/
// 203. 移除链表元素

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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *p = head, *q;
        while (p != NULL && p->next != NULL) {
            if (p->next->val == val) {
                q = p->next;
                p->next = q->next;
                delete q;
            } else { p = p->next; }
        }
        if (head != NULL && head->val == val) {
            q = head;
            head = head->next;
            delete q;
        }
        return head;
    }
};

// other (better) method

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
    ListNode* removeElements(ListNode* head, int val) {
        if (head == NULL) return head;
        head->next = removeElements(head->next, val);
        if (head->val == val) {
            ListNode *p = head;
            head = head->next;
            delete p;
        }
        return  head;
    }
};

// ---------------------------------------------------------------------------


// ---------------------------------------------------------------------------


// ---------------------------------------------------------------------------


// ---------------------------------------------------------------------------


// ---------------------------------------------------------------------------


// ---------------------------------------------------------------------------


// ---------------------------------------------------------------------------
