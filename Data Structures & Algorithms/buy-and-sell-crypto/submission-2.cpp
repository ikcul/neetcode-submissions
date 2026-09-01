class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //essentially have a tracker for the min and the max as you go through it

        int l = 0, n = prices.size(), min = prices[0];

        for (int r = 0; r < n; r++){
            min = std::min(min, prices[r]);
            l = std::max(l, prices[r] - min);
        }
        return l;
    }
};
