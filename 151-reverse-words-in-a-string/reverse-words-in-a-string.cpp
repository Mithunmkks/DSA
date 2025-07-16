class Solution {
public:
    string reverseWords(string s) {
        while(s.back()==' ')s.pop_back();
        int cnt =0;
        while(s[cnt]==' ')cnt++;
        s=s.substr(cnt);

        string ans = "";
        string temp="";
        
        for(int i=0;i<s.size();i++)
        {
            if(s[i]!=' ')temp.push_back(s[i]);
            else 
            {
                if(s[i]==s[i-1])continue;
                else {
                    ans=temp+" "+ans;
                    temp="";
                }
            }

        }
        ans=temp+" "+ans;
        ans.pop_back();
        return ans;
    }
};