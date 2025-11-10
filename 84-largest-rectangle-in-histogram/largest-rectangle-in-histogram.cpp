class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> ls(n),rs(n);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(!st.empty())ls[i]=st.top();
            else ls[i]=-1;
            st.push(i);
        }
        while (!st.empty()) {
    st.pop();
}
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(!st.empty())rs[i]=st.top();
            else rs[i]=n;
            st.push(i);

        }
        
        int ans = 0;

        for(int i=0;i<n;i++){
            int l = rs[i]-ls[i]-1;
            int h = heights[i];
            ans = max(ans,l*h);
        }

        return ans;





    }
};