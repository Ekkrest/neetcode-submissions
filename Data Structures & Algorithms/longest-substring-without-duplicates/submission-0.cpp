class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> umap;
        int ans = 0;
        int l = 0;
        int r = 0;

        for(r; r < s.length(); r++){
            if(!umap.contains(s[r])){
                umap[s[r]] = r;
            }else{
                l = max(l, umap[s[r]] + 1);                
                umap[s[r]] = r;
            }

            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};
