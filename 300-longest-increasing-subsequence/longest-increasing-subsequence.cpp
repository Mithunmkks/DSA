class Solution {
public:
    // 0 , 10 ,1 , 2 , 3 , 15
    // 5       4    3    2     1 
 
    int lengthOfLIS(vector<int>& nums) {
       int n = nums.size();
       vector<int> dp(n,1);
       for(int i=n-1;i>=0;i--){
        int cur = nums[i];
        for(int j=i+1;j<n;j++){
            if(cur<nums[j])dp[i]=max(dp[i],1+dp[j]);
        }
       }
       return *max_element(dp.begin(),dp.end());
    }
};