class Solution {
public:
    int uniqueCount(int n,vector<int> &dp){
        if(n==0)return 1;
        if(n==1)return 10;
        if(dp[n]!=-1)return dp[n];
        int ans = 9;
        int i=9;
        int k = n-1;
        while(k--){
            ans*=i;
            i--;
        }
        return  dp[n]=ans+uniqueCount(n-1,dp);

    }
    int countNumbersWithUniqueDigits(int n) {
        vector<int> dp(n+1,-1);
        return uniqueCount(n,dp);
    }
};