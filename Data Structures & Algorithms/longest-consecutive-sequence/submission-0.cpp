class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::unordered_set<int> consecutive;

        for (size_t i = 0; i < nums.size(); i++){
            consecutive.insert(nums[i]);
        }

        int max = 0;

        for (int i : consecutive){
            if (consecutive.find(i-1) != consecutive.end()){
                continue;
            }else{
                int start = i;
                int local_max = 0;
                while (consecutive.find(start) != consecutive.end()){
                    local_max++;
                    start++;
                }
                if (local_max > max){
                    max = local_max;
                }
            }
        }
        return max;
    }
};
