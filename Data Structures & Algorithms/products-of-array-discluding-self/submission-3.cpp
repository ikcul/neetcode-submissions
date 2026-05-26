class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> sol;

        int temp = 1;
        bool zp = false;
        int zc = 0;
        for (int c : nums){
            if (c != 0){
                temp *= c;
            }else{
                zp = true;
                zc++;
            }
        }

        for (size_t i = 0; i < nums.size(); i++){
            if ((zp && nums[i] != 0) | zc > 1){
                sol.push_back(0);
            } else if (!zp){
                sol.push_back(temp/nums[i]);
            }else{
                sol.push_back(temp);
            }
        }

        return sol;
    }
};
