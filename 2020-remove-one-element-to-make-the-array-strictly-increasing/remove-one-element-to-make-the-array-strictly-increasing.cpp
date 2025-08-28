class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        int n = nums.size();
        if(n<=2)return true;
        int l = 0 , r=n-1;
        while(l+1<r && nums[l]<nums[l+1])l++;
        while(r-1>l && nums[r]>nums[r-1])r--;

        if(abs(l-r)!=1)return false;
        if(l==0 || r==n-1)return true;

        if(nums[l]<nums[r+1])return true;
        if(nums[r]>nums[l-1])return true;
        return false;


        
    }
};