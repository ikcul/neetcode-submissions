class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> complement;
        unsigned int size = nums.size();
        vector<int> solution;

        for (int i = 0; i < size; i++){
            if (complement.find(target-nums[i]) != NULL){
                solution.push_back(complement[target-nums[i]]);
                solution.push_back(i);
            }

            complement[nums[i]] = i;
        }

        return solution;
        
    }
};
