class Solution {
public:
    int compareVersion(string v1, string v2) {
        v1.push_back('.');
        v2.push_back('.');
        int s1=0,e1=0;
        int s2=0,e2=0;
        while(e1<v1.size() || e2<v2.size())
        {
            int a=0,b=0;
            while(v1[e1]!='.' && e1<v1.size())e1++;
            while(v2[e2]!='.' && e2<v2.size())e2++;
            if(e1<v1.size())a=stoi(v1.substr(s1,e1-s1));
            if(e2<v2.size())b=stoi(v2.substr(s2,e2-s2));
            if(a>b)return 1;
            else if(a<b) return -1;
            else 
            {
                s1=++e1;
                s2=++e2;
            }
        }
        return 0;

        
        
    }
};