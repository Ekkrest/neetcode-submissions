class KthLargest {
private:
    std::priority_queue<int, vector<int>, greater<int>> min_heap;
    int k_size;
public:
    KthLargest(int k, vector<int>& nums) {
        k_size = k;
        for(int n:nums){
            add(n);
        }
    }
    
    int add(int val) {
        min_heap.push(val);

        if(min_heap.size() > k_size){
            min_heap.pop();
        }

        return min_heap.top();
    }
};
