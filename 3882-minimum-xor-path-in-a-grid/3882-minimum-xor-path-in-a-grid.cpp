class Solution {
public:
    int dpcheck(int i, int j, int xo, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp) {
        if (i == 0 && j == 0) return xo ^ grid[0][0];
        if (dp[i][j][xo] != -1) return dp[i][j][xo];

        int count1 = INT_MAX, count2 = INT_MAX;
        if (i > 0) count1 = dpcheck(i-1, j, xo ^ grid[i][j], grid, dp);
        if (j > 0) count2 = dpcheck(i, j-1, xo ^ grid[i][j], grid, dp);

        return dp[i][j][xo] = min(count1, count2);
    }

    int minCost(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(10000, -1)));
        return dpcheck(n-1, m-1, 0, grid, dp);
    }
};