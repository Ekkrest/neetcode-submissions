class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0;
        int maxCount=0;
        int ans=0;
        unordered_map<char, int> umap;

        for(int r=0; r < s.size(); r++){
            umap[s[r]]++;
            maxCount = max(maxCount, umap[s[r]]);
            while(r - l + 1 - maxCount > k){
                umap[s[l]]--;
                l++;
            }

            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};
