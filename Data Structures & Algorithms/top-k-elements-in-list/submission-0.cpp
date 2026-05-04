class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        vector<pair<int,int>> items;  // (num, freq)
        vector<int> ans;

        for(int i=0; i<nums.size(); i++){
            if(mp.find(nums[i]) != mp.end())
                mp[nums[i]] += 1;
            else
                mp[nums[i]] = 1;
        }

        for(auto &p : mp){
            items.push_back({p.first, p.second});
        }

        sort(items.begin(), items.end(), [](auto &a, auto &b){
            return a.second > b.second;  // 按出現次數大到小
        });  

        for (int i = 0; i < k; ++i) {
            ans.push_back(items[i].first);
        }

        return ans;
    }
};
