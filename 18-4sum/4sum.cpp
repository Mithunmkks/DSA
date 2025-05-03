class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n-3;i++)
        {
            if(i>0 && nums[i]==nums[i-1])continue;
            for(int j=i+1;j<n-2;j++)
            {
                if(j>i+1 && nums[j]==nums[j-1])continue;
                long long  need= (long long )target - nums[i]-nums[j];
                int l=n-1;
                int k=j+1;
                while(k<l)
                {                    
                if(nums[l]+nums[k]==need){
                ans.push_back({nums[i],nums[j],nums[k],nums[l]});
                l--;
                k++;
                while(k<l && nums[l]==nums[l+1])l--;
                while(k<l && nums[k]==nums[k-1])k++;
                }
                else if(nums[k]+nums[l]<need)k++;
                else l--;

                }
            }
        }
        return ans;
        
    }
};