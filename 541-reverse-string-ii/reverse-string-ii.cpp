class Solution {
public:
    void rev(string &s,int i,int j){
        while(i<j)swap(s[i++],s[j--]);
    }
    string reverseStr(string s, int k) {
        int n = s.size();
        for(int i=0;i<n;i+=2*k)
        {
            int cur = 0;
            for(int j=i;j<n;j++){
                cur++;
                if(cur%k==0){
                    rev(s,i,j);
                    break;
                }
            }
            if(cur<k)rev(s,i,s.size()-1);
        }
        return s;
    }
};