class Solution {
public:
    int rob(vector<int>& nums) {

        if(nums.size() == 1) return nums[0];
        int ans = max(solve(nums, 0, nums.size() - 2), solve(nums, 1, nums.size() - 1));

        return ans;
    }

    int solve(vector<int>& nums, int start, int end){
        int n=end-start+1;
        if (n <= 0) return 0;
        if(n==1) return nums[start];
        if(n==2) return max(nums[start], nums[start + 1]);
        vector<int> dp(n, 0);

        dp[0] = nums[start];
        dp[1] = max(nums[start], nums[start+1]);
        for (int j = 2; j < n; j++) {
            int i = start + j; 
            dp[j] = max(dp[j - 1], dp[j - 2] + nums[i]);
        }

        return dp.back();
    }
};
