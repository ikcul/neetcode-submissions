class KthLargest {
private:
    int k;
    priority_queue<int, vector<int>, std::greater<int>> mheap;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (int i : nums){
            mheap.push(i);
            if (mheap.size() > this->k){
                mheap.pop();
            }
        }
    }
    
    int add(int val) {
        mheap.push(val);
        if (mheap.size() > k){
            mheap.pop();
        }
        
        return mheap.top();
    }
};
