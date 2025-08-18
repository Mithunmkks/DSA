class Solution {
public:
    int dp[5001][2];
    int f(int ind,int buy,vector<int>&prices){
        if(ind>=prices.size())return 0;
        if(dp[ind][buy]!=-1)return dp[ind][buy];
        int profit = 0;
        if(buy){
            profit=max(profit,-prices[ind]+f(ind+1,0,prices));
            profit=max(profit,f(ind+1,1,prices));
        }
        else {
            profit=max(profit,prices[ind]+f(ind+2,1,prices));
            profit=max(profit,f(ind+1,0,prices));
        }
        return dp[ind][buy]=profit;
    }
    int maxProfit(vector<int>& prices) {
memset(dp, -1, sizeof(dp));
return f(0,1,prices);

    }
};