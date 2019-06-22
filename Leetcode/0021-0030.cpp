// https://leetcode-cn.com/problems/merge-two-sorted-lists/
// 21. 合并两个有序链表

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL)  return l2;
        if(l2 == NULL)  return l1;
        
        if (l1->val <= l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};

// ---------------------------------------------------------------------------

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/merge-k-sorted-lists/
// 23. 合并K个排序链表

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    struct cmp {
        bool operator () (ListNode *a, ListNode *b) {
            return a->val > b->val;
        }
    };
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> q;
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i]) q.push(lists[i]);
        }
        ListNode *head = NULL, *pre = NULL, *tmp = NULL;
        while (!q.empty()) {
            tmp = q.top();
            q.pop();
            if (!pre) head = tmp;
            else pre->next = tmp;
            pre = tmp;
            if (tmp->next) q.push(tmp->next);
        }
        return head;
    }
};

// ---------------------------------------------------------------------------

// ---------------------------------------------------------------------------

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/
// 26. 删除排序数组中的重复项

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0)  return 0;
        int i = 0;
        for (int j = 1; j < nums.size(); j++) {
            if (nums[i] != nums[j]) {
                i++;
                nums[i] = nums[j];
            }
        }
        return i + 1;
    }
};

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/remove-element/
// 27. 移除元素

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int size = nums.size();
        int len = 0;
        for (int i = 0; i < size; i++) {
            if (nums[i] != val) {
                if (i != len) {
                    nums[i] = nums[i] + nums[len];
                    nums[len] = nums[i] - nums[len];
                    nums[i] = nums[i] - nums[len];
                }
                len++;
            }
        }
        return len;
    }
};

// ---------------------------------------------------------------------------

// ---------------------------------------------------------------------------

// ---------------------------------------------------------------------------


