class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>> max_heap;

        for (vector<int> i : points){
            int x = i[0];
            int y = i[1];
            int dist = x*x + y*y;
            max_heap.push({dist, {x, y}});
            if (max_heap.size() > k){
                max_heap.pop();
            }
        }
        vector<vector<int>> result;

        while (!max_heap.empty()){
            result.push_back(max_heap.top().second);
            max_heap.pop();
        }
        return result;
    }
};
