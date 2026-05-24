class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> complementSum;

        for (size_t i = 0; i < nums.size(); i++){
            complementSum[target - nums[i]] = i;
        }

        std::vector<int> sol;

        for (size_t i = 0; i < nums.size(); i++){
            if (complementSum.contains(nums[i]) && i != complementSum[nums[i]]){
                sol.push_back(i);
                sol.push_back(complementSum[nums[i]]);
                break;
            }
        }

        return sol;
    }
};
