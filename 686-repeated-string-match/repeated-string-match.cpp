class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        string s = a;
        int c=1;
        while(a.size()<b.size()){a+=s;c++;}
        for(int i=0;i<a.size();i++)
        {
            if(a[i]==b[0])
            {
                if(a.substr(i,b.size())==b)
                {
                    return c;
                }
            }
        }
        a+=s;
        c++;
        for(int i=0;i<a.size();i++)
        {
            if(a[i]==b[0])
            {
                if(a.substr(i,b.size())==b)
                {
                    return c;
                }
            }
        }
        return -1;

    }
};