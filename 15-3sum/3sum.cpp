class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        for(int i =0;i<n;i++)
        {
            if(i>0 && nums[i]==nums[i-1])continue;
            int k=n-1,j=i+1;
            while(j<k)
            {

                if(nums[i]+nums[j]+nums[k]==0){  
                ans.push_back({nums[i],nums[j],nums[k]});
                j++;
                k--;
                while(j<k && nums[j]==nums[j-1])j++;
                while(j<k && nums[k]==nums[k+1])k--;
                }
                else if (nums[i]+nums[j]+nums[k]>0)k--;
                else j++;
            }
        }
        return ans;
    }
};