class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> umap;

        for(string s:strs){
            vector<int> freq(26, 0);
            for(char c:s){
                freq[c-'a']++;
            }
            string key="";
            for(int i=0; i<26; i++){
                key += '#' + freq[i];
            }

            umap[key].push_back(s); 
        }

        vector<vector<string>> res;
        res.reserve(umap.size());

        for(auto& [s, lst]:umap){
            res.push_back(lst);
        }

        return res;
     }
};
