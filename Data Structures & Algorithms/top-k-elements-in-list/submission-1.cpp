class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::map<int, int> temp;

        for (int n : nums){
            temp[n]++;
        }

        std::priority_queue<std::pair<int, int>> pq;
        for (auto it = temp.begin(); it != temp.end(); ++it){
            pq.push({it->second, it->first});
        }

        vector<int> solution;
        for (int i = 0; i < k; i++){
            solution.push_back(pq.top().second);
            pq.pop();
        }
        return solution;
    }  
};
