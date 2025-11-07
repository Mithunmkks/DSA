class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        for(int i=0;i<num.size();i++){
            while(!st.empty() && st.top()>num[i] && k>0){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        while(k--)st.pop();
        string ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        int idx = 0;
        while (idx < ans.size() && ans[idx] == '0') idx++;
        ans = ans.substr(idx);

        return ans.empty() ? "0" : ans;

        
    }
};