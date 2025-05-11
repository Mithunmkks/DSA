class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int dup =0;
        int n=nums.size();
        if(n==1)return n;
        for(int i=n-2;i>=0;i--)
        {
            if(nums[i]==nums[i+1])
            {
                dup++;
                int j=i;
                while(j<n-1){swap(nums[j],nums[j+1]);j++;}
            }
        }
        return n-dup;


        
    }
};