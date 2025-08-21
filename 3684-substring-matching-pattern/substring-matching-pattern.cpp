class Solution {
public:
    bool hasMatch(string s, string p) {
        int i=0;
        string a,b;
        int n = s.size(),m=p.size();
        for(;i<m;i++){
            if(p[i]=='*')break;
            a.push_back(p[i]);
        }
        i++;
        for(;i<m;i++){
            if(p[i]=='*')break;
            b.push_back(p[i]);
        }

        int x =s.find(a);
        if(x==string::npos)return false;
        x+=a.size();
        s=s.substr(x);
        return s.find(b) != string::npos;
    }
};