class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> complement;
        size_t size = nums.size();
        vector<int> solution;

        // i + j = target
        // i = target - j

        for (size_t i = 0; i < size; i++){
            if (complement.find(target - nums[i]) != nullptr){
                solution.push_back(complement[target - nums[i]]);
                solution.push_back(i);
            }
            complement[nums[i]] = i;
        }
        
        return solution;
    }
};
