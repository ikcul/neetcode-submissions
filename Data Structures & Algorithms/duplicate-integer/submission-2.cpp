class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_map<int, int> table;
        for (int num : nums){
            if (table.contains(num)){
                return true;
            }
            table.insert({num, 1});
        }
        return false;
    }
};