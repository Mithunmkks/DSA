class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int n = nums.size();
        if(n==1)return nums[0];
        sort(nums.begin(),nums.end());
        int ans =0;
        for(int i=1;i<n;i+=2)ans+=min(nums[i],nums[i-1]);
        return ans;

    }
};