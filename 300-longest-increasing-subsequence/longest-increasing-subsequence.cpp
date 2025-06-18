class Solution {
public:
    int dp[2501][2502];
    int f(int ind, int prev, vector<int>&nums)
    {
        if(ind>=nums.size())return 0;
        if(dp[ind][prev+1]!=-1)return dp[ind][prev+1];
        int take = 0;
        if(prev==-1)
        {
            take = 1 + f(ind+1,ind,nums);
        }
        else if(nums[ind]>nums[prev])
        {
            take = 1+f(ind+1,ind,nums);
        }
        int nottake = f(ind+1,prev,nums);
        return dp[ind][prev+1] =  max(take,nottake);
    }
    int lengthOfLIS(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return f(0,-1,nums);
    }
};