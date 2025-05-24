class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int n = heights.size();
        int ans =0;
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && heights[st.top()]>heights[i])
            {
                int h = st.top();
                st.pop();
                int prev = st.size()==0?-1:st.top();
                ans=max(ans,heights[h]*(i-prev-1));
            }
            st.push(i);
        }
        while(!st.empty())
            {
                int h = st.top();
                st.pop();
                int prev = st.size()==0?-1:st.top();
                ans=max(ans,heights[h]*(n-prev-1));
            }

        return ans;
    }
};