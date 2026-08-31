class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        if (cost.size() == 1){
            return cost[0];
        }
        else if (cost.size() == 2){
            return std::min(cost[0], cost[1]);
        }
        int n = cost.size();
        vector<int> dp(n+1);
        dp[0] = 0;
        dp[1] = 0;
        for (int i = 2; i < n + 1; i++){
            dp[i] = std::min(dp[i-2] + cost[i - 2], cost[i - 1] + dp[i-1]);
        }

        return dp[n];
    }
};
