class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> umap;
        int largest_val = INT_MIN;
        int res;

        for(int i:nums) umap[i]++;

        for (const auto& [key, value] : umap) {
            if(value > largest_val){
                largest_val = value;
                res = key;
            }
        }

        return res;
    }
};