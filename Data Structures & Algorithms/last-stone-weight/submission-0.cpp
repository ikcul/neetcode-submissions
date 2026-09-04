class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> mheap(stones.begin(), stones.end());

        while (mheap.size() > 1){
            int first = mheap.top();
            mheap.pop();
            int second = mheap.top();
            mheap.pop();

            if (first != second){
                mheap.push(first - second);
            }
        }
        return mheap.empty() ? 0 : mheap.top();
    }
};
