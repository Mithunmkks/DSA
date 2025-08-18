class Solution {
public:
    int maxiProfit(int ind,int pre,vector<int> &prices,vector<vector<int>> &dp2){
        if(ind>=prices.size())return 0;
        if(dp2[ind][pre+1]!=-1)return dp2[ind][pre+1];
        int buy = 0;
        int sell =0;
        int notBuy = maxiProfit(ind+1,pre,prices,dp2);
        if(pre==-1){
            buy =  maxiProfit(ind+1,ind,prices,dp2);
        }
        else{
            sell = prices[ind]-prices[pre] + maxiProfit(ind+2,-1,prices,dp2);
        }
        return dp2[ind][pre+1]=max({notBuy,buy,sell});
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp2(n,vector<int>(n+1,-1));
        return maxiProfit(0,-1,prices,dp2);

        // vector<vector<int>> dp(n+5,vector<int>(n+5,0));
        // for(int i=n-1;i>=0;i--){
        //     for(int pre=-1;pre<i;pre++){
        //         int buy = 0;
        //         int sell = 0;
        //         if(pre==-1){
        //             buy = dp[i+1][i+1];
        //         }
        //         else{
        //             sell = prices[i]-prices[pre]+dp[i+2][pre+1];
        //         }
        //         dp[i][pre]=max(buy,sell);
        //     }
        // }
        // return dp[0][0];
    }
};