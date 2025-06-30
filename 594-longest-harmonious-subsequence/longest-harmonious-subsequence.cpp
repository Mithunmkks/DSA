class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        map<int,int> mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]=i;
        }
        int ans =0;
        for(int i=0;i<nums.size();i++)
        {
            if(mp.find(nums[i]+1)!=mp.end())
            {
                int j = mp[nums[i]+1];
                ans=max(ans,j-i+1);
            }
        }
        return ans;

        


    }
};