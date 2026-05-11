class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int r = 0;
        int l = 0;
        int ans = 0;
        unordered_map<char, int> umap;

        for(r; r < s.size(); r++){
            if(umap.find(s[r]) != umap.end()){
                l = max(l, umap[s[r]] + 1);
            }
            umap[s[r]] = r;
            
            ans = max(ans, r - l + 1);

        }
        return ans;
    }
};
