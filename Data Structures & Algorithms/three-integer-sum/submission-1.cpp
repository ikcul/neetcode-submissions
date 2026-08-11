class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.size() - 1, middle = left + 1;
        vector<vector<int>> sol;
        
        while (left < nums.size()){
            while (middle < right){
                int sum = nums[left] + nums[right] + nums[middle];
                if (sum > 0){
                    right--;
                }else if (sum < 0){
                    middle++;
                }else if (sum == 0){
                    sol.push_back({nums[left], nums[middle], nums[right]});
                    while (middle < right && nums[middle] == nums[middle + 1]) middle++;
                    while (middle < right && nums[right] == nums[right-1]) right--;
                    middle++;
                    right--;
                }
            }
            while (left < right && nums[left] == nums[left + 1])left++;
            left++;
            middle = left + 1;
            right = nums.size() - 1;
        }
        return sol;
    }
};
