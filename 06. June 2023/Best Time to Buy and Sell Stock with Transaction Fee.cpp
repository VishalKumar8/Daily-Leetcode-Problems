class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int buy = -prices[0], sell = 0;
        for(int i=0; i<n; i++){
            int temp = buy;
            buy = max(buy, sell - prices[i]);
            sell = max(sell, temp+prices[i] - fee);
        }
        return sell;
    }
};
