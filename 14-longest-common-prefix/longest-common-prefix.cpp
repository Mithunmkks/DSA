class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string s = strs[0];
        if(strs.size()==1)return strs[0];
        int len = 0;
        for(int i=0;i<s.size();i++)
        {
            for(int j=1;j<strs.size();j++)
            {
                if(strs[j].size()>len){
                if(s[i]!=strs[j][i])
                {
                    return s.substr(0,len);
                }
                }
                else 
                {
                    return s.substr(0,len);
                }
            }
            len++;
        }
        return strs[0];
    }
};