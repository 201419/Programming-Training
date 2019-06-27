

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/
// 83. 删除排序链表中的重复元素

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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *p = head;
        while (p != NULL && p->next != NULL) {
            if (p->val == p->next->val) p->next = p->next->next;
            else p = p->next;
        }
        return head;
    }
};

// second method

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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *p = head, *q;
        while (p != NULL && p->next != NULL) {
            if (p->val == p->next->val) {
                q = p->next;
                p->next = q->next;
                delete q;
            } else { p = p->next; }
        }
        return head;
    }
};

// ---------------------------------------------------------------------------


// ---------------------------------------------------------------------------


// ---------------------------------------------------------------------------


// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/merge-sorted-array/
// 88. 合并两个有序数组

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p = m-- + n-- - 1;
        while (m >= 0 && n >= 0) {
            nums1[p--] = nums1[m] > nums2[n] ? nums1[m--] : nums2[n--];
        }
        while (n >= 0) {
            nums1[p--] = nums2[n--];
        }
    }
};

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/gray-code/
// 89. 格雷编码

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result;
        for (int i = 0; i < (1<<n); i++) {
            result.push_back(i^(i>>1));
        }
        return result;
    }
};

// ---------------------------------------------------------------------------
