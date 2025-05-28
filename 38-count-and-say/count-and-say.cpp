class Solution {
public:
    string rle(string s)
    {
        string ans="";
        int i=0;
        char x = s[0];
        int cnt=0;
        while(i<s.size())
        {
            if(s[i]==x)
            {
                cnt++;
            }
            else 
            {
                ans.push_back('0'+cnt);
                ans.push_back(x);
                x=s[i];
                cnt=1;
            }
            i++;
        }
        if(cnt>0)
        {
            ans.push_back('0'+cnt);
            ans.push_back(x);
        }
        return ans;

    }
    string countAndSay(int n) {
        if(n==1)return "1";

        return rle(countAndSay(n-1));
    }
};