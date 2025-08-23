class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int mini = n;
        stack<int> st;
        for (int i = 0; i < n; i++) {
            if (!st.empty() && nums[i] < nums[st.top()]) {
                while (!st.empty() && nums[i] < nums[st.top()]){
                    mini=min(mini,st.top());
                    st.pop();
                }
            }
            st.push(i);
        }
        // clear stack
        while (!st.empty()) {
            st.pop();
        }
        int maxi =0;
        for (int i = n - 1; i >= 0; i--) {
            if (!st.empty() && nums[i] > nums[st.top()]) {
                while (!st.empty() && nums[i] > nums[st.top()]){
                    maxi=max(maxi,st.top());
                    st.pop();
                }
            }
            st.push(i);
        }
        if(maxi>mini)return maxi-mini+1;
        else return 0;
        


    }
};