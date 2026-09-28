class Solution {
public:
    int dpcheck(bool yes, int index, int n, int trans, vector<int> &nums, vector<vector<vector<int>>> &dp){
        if(index == n || trans == 0) return 0;

        if(dp[index][yes][trans] != -1) return dp[index][yes][trans];

        if(yes){
            int buy = -nums[index] + dpcheck(0, index+1, n, trans, nums, dp);
            int skip = dpcheck(1, index+1, n, trans, nums, dp);
            dp[index][yes][trans] = max(dp[index][yes][trans], max(buy, skip));
        }else{
            int sell = nums[index] + dpcheck(1, index+1, n, trans-1, nums, dp);
            int hold = dpcheck(0, index+1, n, trans, nums, dp);
            dp[index][yes][trans] = max(dp[index][yes][trans], max(sell, hold));
        }
        return dp[index][yes][trans];
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (2, vector<int> (k+1, -1)));

        return dpcheck(1,0,n,k,prices,dp);
    }
};