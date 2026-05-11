class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0;
        int r = 0;
        int ans = 0;
        int maxCount = 0;
        unordered_map<char, int> umap;

        for(r; r < s.length(); r++){
            umap[s[r]]++;
            maxCount = max(maxCount, umap[s[r]]);
            int length = r - l + 1;
            if(length - maxCount <= k){
                ans = max(ans, length);
            }else{
                umap[s[l]]--;
                l++;
            }
        }

        return ans;
    }
};
