class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> solution;
        unordered_map<int, int> res;

        for (const auto& num : nums){
            res[num]++;
        }

        //add the k most frequent elements now
        vector<pair<int, int>> temp;

        for (const auto& p : res){
            temp.push_back({p.second, p.first});
        }
        sort(temp.rbegin(), temp.rend());

        for (int i = 0; i < k; i++){
            solution.push_back(temp[i].second);
        }
        return solution;
    }
};
