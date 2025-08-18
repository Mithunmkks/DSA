class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<long long > dp(n+1,INT_MAX);
        vector<long long > fact(primes.size(),1);
        dp[1]=1;
        for(int i=2;i<=n;i++){
            for(int j=0;j<primes.size();j++){
                dp[i]=min(dp[i],dp[fact[j]]*primes[j]);
            }
            for(int j=0;j<primes.size();j++){
                if(dp[i]%primes[j]==0)fact[j]++;
            }
        }
        return dp[n];

    }
};