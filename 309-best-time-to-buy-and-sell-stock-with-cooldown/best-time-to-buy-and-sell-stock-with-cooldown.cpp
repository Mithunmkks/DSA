class Solution {
public:
    int dp[5003][2];
    int f(int ind, int buy, vector<int>& prices) {
        if (ind >= prices.size())
            return 0;
        if (dp[ind][buy] != -1)
            return dp[ind][buy];
        int profit = 0;
        if (buy) {
            profit = max(profit, -prices[ind] + f(ind + 1, 0, prices));
            profit = max(profit, f(ind + 1, 1, prices));
        } else {
            profit = max(profit, prices[ind] + f(ind + 2, 1, prices));
            profit = max(profit, f(ind + 1, 0, prices));
        }
        return dp[ind][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        memset(dp, 0, sizeof(dp));
        // return f(0, 1, prices);
        int n = prices.size();
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<2;j++){
                int p = 0;
                if(j){
                    //take
                    p=max(p,-prices[i]+dp[i+1][1-j]);
                    //notTake
                    p=max(p,dp[i+1][j]);
                }
                else {
                    // take 
                    p=max(p,prices[i]+dp[i+2][1-j]);
                    // notTake
                    p=max(p,dp[i+1][j]);
                }
                dp[i][j]=p;
            }
        }
        return dp[0][1];
    }
};