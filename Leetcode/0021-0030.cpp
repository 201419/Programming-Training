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

// https://leetcode-cn.com/problems/generate-parentheses/
// 22. 括号生成

class Solution {
public:
    vector<string> ans;
    int N;
    
    void dfs(int l,int r,string has) {
        if (r > l)  return;
        if (l > N)  return;
        if (l == r && r == N) {
            ans.push_back(has);
            return;
        }
        dfs(l + 1, r, has + "(");
        dfs(l, r + 1, has + ")");
    }
    
    vector<string> generateParenthesis(int n) {
        N = n;
        if (!N) return {};
        dfs(0, 0, "");
        return ans;
    }
};

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

// ===================

class Solution {
private:
    ListNode* merge(ListNode* list1, ListNode* list2) {
        if (list1 == NULL && list2 == NULL) return NULL;
        else if (list1 != NULL && list2 == NULL) return list1;
        else if (list1 == NULL && list2 != NULL) return list2;
        
        ListNode *head, *p;
        if (list1->val <= list2->val) {
            head = list1;
            list1 = list1->next;
        } else {
            head = list2;
            list2 = list2->next;
        }
        p = head;                     
        while (list1 != NULL && list2 != NULL) {
            if (list1->val <= list2->val) {
                p->next = list1;
                list1 = list1->next;
                p = p->next;
            } else {
                p->next = list2;
                list2 = list2->next;
                p = p->next;
            }
        }
        while (list1 != NULL) {
            p->next = list1;      
            list1 = list1->next;
            p = p->next; 
        }
        while (list2 != NULL) {
            p->next = list2;
            list2 = list2->next;
            p = p->next;  
        }
        p->next = NULL;
        return head;
    }
    
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return NULL;
        
        ListNode *result = lists[0];
        for (int i = 1; i < lists.size(); i++) {
            result = merge(result, lists[i]);
        }
        return result;
    }
};

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/swap-nodes-in-pairs/
// 24. 两两交换链表中的节点

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
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prevNode = dummy;
        ListNode* currentNode = head;
        ListNode* nextNode = head->next;
        while (currentNode != NULL && nextNode != NULL) {
            prevNode->next = nextNode;
            currentNode->next = nextNode->next;
            nextNode->next = currentNode;

            prevNode = currentNode;
            currentNode = currentNode->next;
            if (currentNode != NULL) nextNode = currentNode->next;
        }

        head = dummy->next;
        delete dummy;
        return head;
    }
};

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/reverse-nodes-in-k-group/
// 25. K 个一组翻转链表

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
    pair<ListNode*, ListNode*> myReverse(ListNode* head, ListNode* tail) {
        ListNode* prev = tail->next;
        ListNode* pNode = head;
        while (prev != tail) {
            ListNode* nextNode = pNode->next;
            pNode->next = prev;
            prev = pNode;
            pNode = nextNode;
        }
        return {tail, head};
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* hair = new ListNode(0);
        hair->next = head;
        ListNode* prev = hair;

        while (head) {
            ListNode* tail = prev;
            for (int i = 0; i < k; i++) {
                tail = tail->next;
                if (!tail)  return hair->next;
            }
            ListNode* nextNode = tail->next;
            auto result = myReverse(head, tail);
            head = result.first; tail = result.second;
            prev->next = head;
            tail->next = nextNode;
            prev = tail;
            head = nextNode;
        }

        return hair->next;
    }
};

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

// https://leetcode-cn.com/problems/implement-strstr/
// 28. 实现 strStr()

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/divide-two-integers/
// 29. 两数相除

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/substring-with-concatenation-of-all-words/
// 30. 串联所有单词的子串
