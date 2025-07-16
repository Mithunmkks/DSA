class Solution {
public:
    string longestPalindrome(string s) {
        int len =0;
        string ans="";
        int n = s.size();
        for(int i=0;i<s.size();i++)
        {
            int sz =1;
            int j=i-1,k=i+1;
            while(j>=0 && k<n && s[j]==s[k])
            {
                sz+=2;
                j--;
                k++;
            }
            if(sz>len)
            {
                len = sz;
                ans=s.substr(j+1,sz);
            }
        }
        for(int i=0;i<s.size();i++)
        {
            int sz =0;
            int j=i,k=i+1;
            while(j>=0 && k<n && s[j]==s[k])
            {
                sz+=2;
                j--;
                k++;
            }
            if(sz>len)
            {
                len = sz;
                ans=s.substr(j+1,sz);
            }
        }

        return ans;



    }
};