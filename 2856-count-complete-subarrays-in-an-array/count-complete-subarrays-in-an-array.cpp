class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        map<int,int> mp;
        set<int> st;
        int ans=0;
        for(auto i:nums)st.insert(i);
        int j=0;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
            while(mp.size()==st.size())
            {
                ans+=nums.size()-i;
                mp[nums[j]]--;
                if(mp[nums[j]]==0)
                {
                    mp.erase(nums[j]);
                }
                j++;
            }
        }
        return ans;
            

    }
};