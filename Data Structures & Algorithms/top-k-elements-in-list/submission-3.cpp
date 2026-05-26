class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> tempCounter;

        for (const auto& s : nums){
            tempCounter[s]++;
        }

        vector<int> sol;

        vector<pair<int, int>> tempContainer;

        for (const auto& p : tempCounter){
            tempContainer.push_back({p.second, p.first});
        }

        sort(tempContainer.rbegin(), tempContainer.rend());

        for (int i = 0; i < k; i++){
            sol.push_back(tempContainer[i].second);
        }
        return sol;
    }
};
