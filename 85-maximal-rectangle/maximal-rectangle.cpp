class Solution {
public:
    int maxRectangleArea(vector<int>& vec) {
        int ans = 0;
        stack<int> st;
        int n = vec.size();
        for (int i = 0; i < n; i++) {
            while (!st.empty() && vec[st.top()] > vec[i]) {
                int H = vec[st.top()];
                st.pop();
                int leftind = st.empty() == true ? -1 : st.top();
                int rightind = i;
                int L = rightind - leftind - 1;
                ans = max(ans, L * H);
            }
            st.push(i);
        }
        while (!st.empty()) {
            int H = vec[st.top()];
            st.pop();
            int leftind = st.empty() == true ? -1 : st.top();
            int rightind = n;
            int L = rightind - leftind - 1;
            ans = max(ans, L * H);
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int n = matrix.size();
        int m = matrix[0].size();
        int ans=0;
        vector<int> vec(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1')vec[j]++;
                else vec[j]=0;
            }
            ans=max(ans,maxRectangleArea(vec));
        }
        return ans;
    }
};