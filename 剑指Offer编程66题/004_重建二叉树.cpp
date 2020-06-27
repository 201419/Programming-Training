// 题目描述

// 输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。
// 假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
// 例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。


/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
        if(pre.size()==0 || vin.size()==0) return NULL;
        int size = pre.size();
        return constree(pre, vin, 0, size-1, 0, size-1);
    }
    TreeNode * constree(vector<int> &pre, vector<int> &in, int prei, int prej, int ini, int inj) {
        if(prei>prej || ini>inj) return NULL;
        TreeNode * node = new TreeNode(pre.at(prei));
        int i = ini;
        while(in.at(i)!=pre.at(prei)) i++;
        int len = i - ini;
        node->left = constree(pre, in, prei+1, prei+len, ini, i-1);
        node->right = constree(pre, in, prei+len+1, prej, i+1, inj);
        return node;
    }
};