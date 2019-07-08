// https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/
// 121. 买卖股票的最佳时机

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0)  return 0;
        int currMinPrice = prices[0];
        int maxProfit = 0;
        int currProfit = 0;
        for(int i = 1; i < prices.size(); i++){
            if(prices[i] < currMinPrice)  currMinPrice = prices[i];
            currProfit = prices[i] - currMinPrice;
            if(currProfit > maxProfit)  maxProfit = currProfit;
        }
        return maxProfit;
    }
};

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/
// 122. 买卖股票的最佳时机 II

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i-1] < prices[i])  maxProfit += prices[i] - prices[i-1];
        }
        return maxProfit;
    }
};

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iii/
// 123. 买卖股票的最佳时机 III

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/binary-tree-maximum-path-sum/
// 124. 二叉树中的最大路径和

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
    int result = INT_MIN;
public:
    int maxPathSum(TreeNode* root) {
        if (root == NULL) return NULL;
        
        maxValue(root);
        return result;
    }
    
    int maxValue(TreeNode* root) {
        
        int left = -1, right = -1;
        
        if (root->left != NULL) left = maxValue(root->left);
        if (root->right != NULL) right = maxValue(root->right);
        
        int ret = max(root->val, max(root->val+left, root->val+right));
        
        int maxVal = max(ret, root->val+left+right);
        
        result = max(result, maxVal);
        
        return ret;
    }
};

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/valid-palindrome/
// 125. 验证回文串

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/word-ladder-ii/
// 126. 单词接龙 II

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/word-ladder/
// 127. 单词接龙

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/longest-consecutive-sequence/
// 128. 最长连续序列

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/sum-root-to-leaf-numbers/
// 129. 求根到叶子节点数字之和

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/surrounded-regions/
// 130. 被围绕的区域
