class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unsigned int size = nums.size();
        vector<int> seen;
        for (int i = 0; i < size; i++){
            seen.push_back(nums[i]);
            for (int j = 0; j < i; j++){
                if (nums[i] == nums[j] && i != j){
                    return true;
                }
            }
        }
        return false;
    }
};