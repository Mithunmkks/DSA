class Solution {
public:
    bool play(int n){
        if(n==1)return false;
        for(int i=1;i<n;i++){
            if(n%i==0){
                if(!play(n-i))return true;
            }
        }
        return false;
    }
    bool divisorGame(int n) {
        vector<int> dp(n+1,0);
        for(int i=2;i<=n;i++){
            for(int j=1;j<i;j++){
                if(i%j==0){
                    if(dp[i-j]==0){
                        dp[i]=1;
                        break;
                    }
                }
            }
        }
        return dp[n];
    }
};