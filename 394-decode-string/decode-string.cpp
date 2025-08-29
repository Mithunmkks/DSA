class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
        int i = 0;
        while (i < s.size()) {
            if (s[i] == ']') {
                string temp;
                while (st.top() != '[') {
                    temp = st.top()+temp;
                    st.pop();
                }
                st.pop();
                string  num = "" ;
                while(!st.empty() && isdigit(st.top())){    
                    num=st.top()+num;
                    st.pop();
                }
                cout<<num;
                int number = stoi(num);
                
                string result;
                for (int k= 0; k < number; k++) {
                    result+=temp;
                }
                for(auto ch:result)
                st.push(ch);

                i++;
                
            } else{
                st.push(s[i]);
                i++;
            }
        }
        string res ;
        while(!st.empty()){res.push_back(st.top());st.pop();}
        reverse(res.begin(),res.end());
        return res;
    }
};