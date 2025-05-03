class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        map<int,int> mp;
        mp[0]++;
        int sum=0;
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            if(mp.find(sum-k)!=mp.end())ans+=mp[sum-k];
            mp[sum]++;
        }
       return ans;
    }
};

// 1 2 3
// 3 2 1 