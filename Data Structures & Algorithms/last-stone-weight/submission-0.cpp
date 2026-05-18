class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        std::priority_queue<int> max_heap;
        
        for(int w:stones) max_heap.push(w);

        while(max_heap.size() > 1){
            int x1 = max_heap.top();
            max_heap.pop();
            int x2 = max_heap.top();
            max_heap.pop();
            int diff;

            if(x1 != x2){
                diff = x1 - x2;
                max_heap.push(diff);
            }
        }

        int res = (!max_heap.empty()) ? max_heap.top() : 0;
        return res;
    }
};
