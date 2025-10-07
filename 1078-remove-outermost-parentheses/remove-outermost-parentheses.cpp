class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans  = "";
        int depth = 0;
        stack<char> charStack;
        for(auto ch:s){
            if(ch=='('){
                depth++;
                charStack.push('(');
            }
            else{
                depth--;
                charStack.push(')');
                if(depth==0){
                    string temp;
                    while(!charStack.empty()){
                        temp.push_back(charStack.top());
                        charStack.pop();
                    }
                    temp.pop_back();
                    reverse(temp.begin(),temp.end());
                    temp.pop_back();
                    ans+=temp;
                }
            }
        }
        return ans;
    }
};