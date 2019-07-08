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



// ---------------------------------------------------------------------------



// ---------------------------------------------------------------------------


// ---------------------------------------------------------------------------



// ---------------------------------------------------------------------------



// ---------------------------------------------------------------------------



// ---------------------------------------------------------------------------
