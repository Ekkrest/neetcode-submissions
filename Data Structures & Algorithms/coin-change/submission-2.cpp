// 遞迴 (由上而下)

class Solution {
public:
    vector<int> memo;

    int coinChange(vector<int>& coins, int amount) {
        memo = vector<int> (amount + 1, -666);

        return dp(coins, amount);
    }

    int dp(vector<int>coins, int amount){
        if(amount == 0) return 0;
        if(amount < 0) return -1;

        if (memo[amount] != -666)
            return memo[amount];

        int res = INT_MAX;
        for(int coin : coins){
            int sub = dp(coins, amount - coin);
            if (sub == -1) continue;
            res = min(res, sub + 1);
        }

        memo[amount] = (res == INT_MAX) ? -1 : res;
        return memo[amount];
    }
};
