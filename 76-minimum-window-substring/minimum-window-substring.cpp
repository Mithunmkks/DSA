class Solution {
public:
    string minWindow(string s, string t) {
        if(s==t)return t;
        map<char,int> mp;
        for(auto i:t)
        {
            mp[i]++;
        }
        int j=0,i=0,st=0,len=INT_MAX;
        int count=mp.size();
        while(j<s.size())
        {
            mp[s[j]]--;
            if(mp[s[j]]==0)
            {
                count--;
            }
            if(count==0)
            {
                while(count==0)
                {
                    if((j-i+1)<len)
                    {
                        len=j-i+1;
                        st=i;
                    }
                    mp[s[i]]++;
                    if(mp[s[i]]>0){
                        count++;
                    }
                    i++;
                }
            }
            j++;
        }
        if(len==INT_MAX)
        {
            return "";
        }
        else 
        {
            return s.substr(st,len);
        }
    }
};