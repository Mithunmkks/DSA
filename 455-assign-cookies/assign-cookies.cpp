class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        if(s.size()==0)return 0;
        int ans = 0;
        int n = s.size();
        int j=n-1;
        for(int i=g.size()-1;i>=0;i--){
            if(j>=0 && g[i]<=s[j] ){
                ans++;
                j--;
            }
        }
        return ans;
    }
};