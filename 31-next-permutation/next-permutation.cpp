class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        if(n<2)return ;
        int i=0;
        for(i=n-2;i>=0;i--)
        {
            if(nums[i]<nums[i+1])break;
        }
        if(i<0)
        {
            sort(nums.begin(),nums.end());
            return;
        }
        if(i>=0){
        int j;
        for(j=n-1;j>i;j--)
        {
            if(nums[j]>nums[i])break;
        }
        swap(nums[i],nums[j]);
        }
        sort(nums.begin()+i+1,nums.end());
        return ;


    }
};