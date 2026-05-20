class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> min_heap;

        for(int n : nums){
            if(min_heap.size() >= k){
                int res = min_heap.top();
                if(n > res){
                    min_heap.pop();
                    min_heap.push(n);
                }
            }
            else{
                min_heap.push(n);
            }
        }

        return min_heap.top();
    }
};
