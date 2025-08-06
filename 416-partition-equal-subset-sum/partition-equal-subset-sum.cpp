class Solution {
public:
    bool canPartition(vector<int>& nums) {
        long long sum = accumulate(nums.begin(),nums.end(),0);
        if(sum&1)return false;
        sum /=2;

        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int>(sum+1,1e6));
        for(int i=0;i<n+1;i++)dp[i][0]=0;
        for(int i=n-1;i>=0;i--){
            for(int j=1;j<=sum;j++){
                int take = 1e6;
                if(j>=nums[i])take=1+dp[i+1][j-nums[i]];
                int notTake = dp[i+1][j];
                dp[i][j]=min(take,notTake);
            }
        }
        if(dp[0][sum]>=1e6)return false;
        else return true;



    }
};