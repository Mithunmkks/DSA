class Solution {
public:
    int minOperations(vector<int>& nums) {
        stack<int> st;
        int ans =0;
        for(int i=0;i<nums.size();i++){
            // if(nums[i]==0)nums[i]=INT_MAX;
            while( !st.empty() && nums[i]<st.top()){
            st.pop();
            ans++;
            }
            if(st.empty() || st.top()<nums[i])st.push(nums[i]);

        }
        int cnt = 0;
        while(!st.empty()){
            if(st.top()!=0)cnt++;
            st.pop();
        }
        return ans+cnt;
    }
};