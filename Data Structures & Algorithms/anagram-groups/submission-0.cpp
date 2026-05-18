class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> umap;

        for(string s : strs){
            string key = s;
            sort(key.begin(), key.end());
            umap[key].push_back(s);
        }

        vector<vector<string>> ans;
        ans.reserve(umap.size());

        for(auto pair : umap){
            ans.push_back(move(pair.second));
        }

        return ans;
    }
};
