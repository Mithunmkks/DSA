class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n+1,vector<int>(amount+1,1e5));
        for(int i=0;i<=n;i++)dp[i][0]=0;
        for(int i=n-1;i>=0;i--){
            for(int j=1;j<=amount;j++){
                int take = 1e5;
                if(coins[i]<=j)take=1+dp[i][j-coins[i]];
                int notTake = dp[i+1][j];
                dp[i][j]=min(take,notTake);
            }
        }
        if(dp[0][amount]>=1e5)return -1;
        else return dp[0][amount];
        
    }
};