class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n = s.size();
        vector<int> ans(n+1,0);
        int D=n,I=0;
        for(int i=0;i<n;i++){
            if(s[i]=='D')ans[i]=D--;
            else ans[i]=I++;
        }
        ans[n]=D;
        return ans;
        
    }
};