class Solution {
private: 
   int dpsolve(int n ,vector<int> &dp){
       if(n<=1) return 1;
        if(dp[n] != -1) return dp[n];
        int ans =0 ;
        for(int i=1;i<=n;i++) ans+=dpsolve(i-1,dp)*dpsolve(n-i,dp);
        return dp[n] = ans;
   }
public:
    int numTrees(int n) {
        vector<int> dp(n+1,-1);
        return dpsolve(n,dp);
    }
};