class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        int i=0;
        int n = s.size();
        while(i<n)
        {
            while(s[i]==' ')i++;
            int j=i;
            while(j<n && s[j]!=' ')j++;
            if(i<j){
            st.push(s.substr(i,j-i));
            i=j;
            }
        }
        s="";
        while(!st.empty())
        {
            s+=st.top();
            s+=" ";
            st.pop();
        }
        s.pop_back();
        return s;
        
    }
};