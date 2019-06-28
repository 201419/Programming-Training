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

// https://leetcode-cn.com/problems/reorder-list/
// 143. 重排链表

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/binary-tree-preorder-traversal/
// 144. 二叉树的前序遍历

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/binary-tree-postorder-traversal/
// 145. 二叉树的后序遍历

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/lru-cache/
// 146. LRU缓存机制

class LRUCache {
public:
    LRUCache(int capacity) {
        size = capacity;
    }
    
    int get(int key) {
        if (mp.find(key) != mp.end()) {
            int value = mp[key]->second;
            lt.splice(lt.begin(), lt, mp[key]);
            return value;
        } else {
            return -1;
        }
    }
    
    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            mp[key]->second = value;
            get(key);
        } else {
            lt.emplace_front(key,value);
            mp[key] = lt.begin();
            if (lt.size() > size) {
                mp.erase(lt.back().first);
                lt.pop_back();
            }
        }
    }
    
private:
    unordered_map<int, list<pair<int, int>>::iterator> mp;
    list<pair<int,int>> lt;
    int size;
    
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/insertion-sort-list/
// 147. 对链表进行插入排序

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
    ListNode* insertionSortList(ListNode* head) {
        
        ListNode *p = head, *q1, *q2;
        
        while (p != NULL && p->next != NULL) {
            
            q1 = head; q2 = p->next;
            
            if (q1->val > q2->val) {
                p->next = q2->next;
                q2->next = q1;
                head = q2;
            } else {
                while (q1->next != q2) {
                    if (q1->next->val > q2->val) {
                        p->next = q2->next;
                        q2->next = q1->next;
                        q1->next = q2;
                        break;
                    } else { q1 = q1->next; }
                }
                if (q1 == p) p = p->next;
            }
        }
        return head;
    }
};

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/sort-list/
// 148. 排序链表

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
    ListNode* sortList(ListNode* head) {
        return (head == NULL ? head : merge(head));  
    }
    
    ListNode* merge(ListNode* head){
        if (head->next == NULL) return head;
        
        ListNode *fast = head, *slow = head;
        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *tail = slow;
        slow = slow->next;
        tail->next = NULL;
        
        return mergeList(merge(head), merge(slow));
    }
    
    ListNode* mergeList(ListNode* left, ListNode* right){
        ListNode *head;
        if (left->val < right->val) {
            head = left;
            left = left->next;
        } else {
            head = right;
            right = right->next;
        }
        ListNode *result = head;
        
        while (left != NULL && right != NULL) {
            if (left->val < right->val) {
                head->next = left;
                head = head->next;
                left = left->next;
            } else {
                head->next = right;
                head = head->next;
                right = right->next;
            }
        }
        if (left == NULL) head->next = right;
        else head->next = left;
        
        return result;
    }
};

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/max-points-on-a-line/
// 149. 直线上最多的点数

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/evaluate-reverse-polish-notation/
// 150. 逆波兰表达式求值
