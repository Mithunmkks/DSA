class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int maxi = nums[0];
        int prev = nums[0];
        for(int i=1;i<n;i++)
        {
            int cur=max(0,prev)+nums[i];
            prev=cur;
            maxi=max(prev,maxi);
        }
        return maxi;
        
    }
};