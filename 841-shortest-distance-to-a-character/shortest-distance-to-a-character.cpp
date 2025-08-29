class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n = s.size();
        vector<int> ans(n,1e9);
        int li = -1;
        for(int i=0;i<n;i++){
            if(s[i]==c)li=i;
            if(li!=-1 && i-li<ans[i])ans[i]=i-li;
        }
        li=-1;
        for(int i=n-1;i>=0;i--){
            if(s[i]==c)li=i;
            if(li!=-1 && li-i<ans[i])ans[i]=li-i;
        }
        return ans;
    }
};