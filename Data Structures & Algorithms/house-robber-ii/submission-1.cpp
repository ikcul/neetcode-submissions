class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1){
            return nums[0];
        }
        if (n==2){
            return std::max(nums[0], nums[1]);
        }
        vector<int> dp1(n);
        vector<int> dp2(n);
        dp2[0] = 0;
        dp2[1] = nums[1];
        dp1[0] = nums[0];
        dp1[1] = std::max(dp1[0], nums[1]);
        for (int i = 2; i < n-1; i++){
            dp1[i] = std::max(dp1[i-2] + nums[i], dp1[i-1]);
        }
        for (int i = 2; i < n; i++){
            dp2[i] = std::max(dp2[i-2] + nums[i], dp2[i-1]);
        }
        return std::max(dp2[n-1], dp1[n-2]);
    }
};
