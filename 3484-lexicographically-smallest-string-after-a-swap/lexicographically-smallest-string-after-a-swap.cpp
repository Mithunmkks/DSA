class Solution {
public:
    string getSmallestString(string s) {
        for(int i=0;i<s.size()-1;i++){
            int a = s[i]-'0';
            int b = s[i+1]-'0';
            if(a>b && (a&1)==(b&1)){
                swap(s[i],s[i+1]);
                return s;
            }
        }
        return s;
    }
};