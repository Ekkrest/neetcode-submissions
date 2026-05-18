class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        std::priority_queue<pair<int, vector<int>>> max_heap;

        for(auto& point : points){            
            if(max_heap.size()<k){
                int dist = (point[0]*point[0]) + (point[1]*point[1]);
                max_heap.push({dist, point});
            }else{
                int dist1 = max_heap.top().first;
                int dist2 = (point[0]*point[0]) + (point[1]*point[1]);
                if(dist1 > dist2){
                    max_heap.pop();
                    max_heap.push({dist2, point});
                }
            }
        }
        vector<vector<int>> res;
        while(!max_heap.empty()){
            res.push_back(max_heap.top().second);
            max_heap.pop();
        }

        return res;
    }
};
