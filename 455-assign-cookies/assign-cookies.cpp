class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        if(s.size()==0)return 0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int j = s.size()-1;
        int ans =0;
        for(int i=g.size()-1;i>=0;i--)
        {
            if(j>=0 && g[i]<=s[j] )
            {
                ans++;
                j--;
            }
        }
        return ans;


        
    }
};