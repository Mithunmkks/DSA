class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,0);
        dp[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            dp[i]=max(0,dp[i-1])+nums[i];
        }
        int ans=INT_MIN;
        for(auto &i:dp)ans=max(ans,i);
        return ans;
    }
};