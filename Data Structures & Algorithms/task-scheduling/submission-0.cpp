class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        std::priority_queue<int> max_heap;
        std::vector<int> freq(26, 0);
        int time = 0;
        int res;

        for(char c : tasks) {
            freq[c - 'A']++;
        }
        
        for(int i = 0; i < 26; i++){
            if(freq[i] > 0){
                max_heap.push(freq[i]);
            }
        }
        std::queue<std::pair<int, int>> cooling_queue;

        while(!max_heap.empty() || !cooling_queue.empty()){
            if(!cooling_queue.empty()){
                if(time == cooling_queue.front().second){
                    max_heap.push(cooling_queue.front().first);
                    cooling_queue.pop();
                }
            }
            if(!max_heap.empty()){
                res = max_heap.top();
                max_heap.pop();
                if(res - 1 > 0){
                    cooling_queue.push({res - 1, time + n + 1});
                }
            }
            time++;
        }
        
        return time;
    }
};
