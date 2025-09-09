class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n);
        for(int i=0;i<n;i++){
            int prev1 = i>0?dp[i-1]:0;
            int prev2 = i>1?dp[i-2]:0;
            dp[i]=cost[i]+min(prev1,prev2);
        }
        return min(dp[n-1],dp[n-2]);
    }
};