class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> umap;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
        for(int i : nums){
            umap[i]++;
        }

        for(auto& it:umap){
            min_heap.push({it.second, it.first});
            if(min_heap.size() > k){
                min_heap.pop();
            }
        }

        vector<int> res;
        while(!min_heap.empty()) {
            // min_heap.top() 是一個 pair<int, int> -> {频率, 数字}
            // 我們需要的是數字，所以取 .second
            res.push_back(min_heap.top().second); 
            min_heap.pop(); // 拿完記得彈出，這樣下次 .top() 才會看到下一個
        }

        return res;
        

    }
};
