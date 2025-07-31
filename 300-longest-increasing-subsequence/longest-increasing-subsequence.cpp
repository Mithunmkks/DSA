class Solution {
public:


    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1,0);
        for(int i=n-1;i>=0;i--){
            vector<int> t(n+1,0);
            for(int j=i-1;j>=-1;j--){
                int take = 0;
                if(j==-1 || nums[i]>nums[j])take=1+dp[i+1];
                int notTake = dp[j+1];
                t[j+1]=max(take,notTake);
            }
            dp=t;
        }
        return dp[0];
    }
};