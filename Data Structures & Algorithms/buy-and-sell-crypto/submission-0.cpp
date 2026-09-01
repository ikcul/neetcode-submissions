class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int n = prices.size();
        vector<int> dp(n);
        int min = prices[0];
        for (int i = 0; i < n; i++){
            if (prices[i] < min){
                min = prices[i];
            }
            profit = std::max(profit, prices[i] - min);
        }
        return profit;
    }
};
