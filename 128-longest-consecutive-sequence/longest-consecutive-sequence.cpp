class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> st(nums.begin(),nums.end());
        set<int> unique;
        int ans =0;
        for(int i=0;i<nums.size();i++)
        {
            int x = nums[i];
            int cnt =1;
            if(st.find(x-1)==st.end() && unique.find(x)==unique.end()){
            unique.insert(x);
            while(st.find(x+1)!=st.end())
            {
                x++;
                cnt++;
            }
            }
            ans=max(ans,cnt);
        }
        return ans;
        
    }
};