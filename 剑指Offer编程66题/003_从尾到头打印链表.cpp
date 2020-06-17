/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> vec;
        printNext(head,vec);
        return vec;
    }
    void printNext(ListNode *head, vector<int> &vec){
        if(head==NULL) return;
        printNext(head->next,vec);
        vec.push_back(head->val);
    }
};

/* ============================================= */

/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        stack<int> nodes;
         
        ListNode* pNode = head;
        while (pNode != NULL) {
            nodes.push(pNode->val);
            pNode = pNode->next;
        }
         
        vector<int> res;
        while (!nodes.empty()) {
            res.push_back(nodes.top());
            nodes.pop();
        }
        return res;
    }
};
