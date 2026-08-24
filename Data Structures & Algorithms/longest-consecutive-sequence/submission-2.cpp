class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> count;
        for (int i : nums){
            count.insert(i);
        }
        unordered_set<int> seen;
        int max = 0;
        for (int c : count){
            if (count.find(c-1) != count.end()){
                continue;
            }else{
                int local_max = 1;
                while (count.find(c + 1) != count.end()){
                    local_max++;
                    c++;
                }
                if (local_max > max){
                    max = local_max;
                }
            }
        }
        return max;
    }
};
