class Solution {
public:
    int f(int l,int h,vector<vector<int>> &dp){
        if(l>=h)return 0;
        int ans = INT_MAX;
        if(dp[l][h]!=-1)return dp[l][h];
        for(int mid=l;mid<=h;mid++){
            int cost = mid+max(f(l,mid-1,dp),f(mid+1,h,dp));
            ans =  min(ans,cost);
        }
        return  dp[l][h] = ans;
    }
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return f(1,n,dp);

    }
};