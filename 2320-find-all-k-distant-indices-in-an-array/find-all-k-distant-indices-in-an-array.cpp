class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        set<int> ans;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==key)
            {
                int p =i;
                while(p-i<=k && p<nums.size())
                {
                    ans.insert(p);
                    p++;
                }
                p=i-1;
                while(i-p<=k && p>=0)
                {
                    ans.insert(p);
                    p--;
                }
            }
        }
        vector<int> st(ans.begin(),ans.end());
        sort(st.begin(),st.end());
        return st;
    }
};