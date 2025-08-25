class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0,lastIndex=0;
        sort(nums.begin(),nums.end());
        vector<int> dp(n,1),seq(n,0);
        for(int i=1;i<n;i++){
            seq[i]=i;
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0 && dp[j]+1>dp[i]){
                    
                    dp[i]=dp[j]+1;
                    seq[i]=j;

                }
            }
            if(dp[i]>maxi){
                maxi=dp[i];
                lastIndex=i;
            }
        }
        vector<int> ans;
        ans.push_back(nums[lastIndex]);
        cout<<endl;
        for(auto &i:seq)cout<<i<<" ";
        while(seq[lastIndex]!=lastIndex){
            ans.push_back(nums[seq[lastIndex]]);
            lastIndex=seq[lastIndex];
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};