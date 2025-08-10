class Solution {
public:
    int minJumps(int ind,vector<int>&nums){
        if(ind>=nums.size() || nums[ind]==0){
            return 1e6;
        }
        if(ind==nums.size()-1){
            return 0;
        }
        int ans = INT_MAX;
        for(int i=1;i<=nums[ind];i++){
            int jump = 1+minJumps(ind+i,nums);
            ans=min(jump,ans);
        }
        return ans;
    }
    int jump(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return 0;
        vector<int> dp(n,0);
        for(int i=n-2;i>=0;i--){
            int jump = INT_MAX;
            if(nums[i]==0){
                dp[i]=1e6;
                continue;
            }
            for(int j=1;j<=nums[i];j++){
                if(i+j<n)jump=min(jump,dp[i+j]);
            }
            dp[i]=1+jump;
        }
        return dp[0];
    }
};