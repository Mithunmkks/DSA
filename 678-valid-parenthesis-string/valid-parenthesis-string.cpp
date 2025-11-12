class Solution {
public:
    bool checkValidString(string s) {
        int l = 0,r=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                l++;
                r++;
            }
            else if(s[i]==')'){
                l--;
                r--;
            }
            else {
               l--;
               r++;
               
            }
            if(l<0)l=0;
               if(r<0)return false;
        }
        return l==0;
    }
};