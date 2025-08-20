class Solution {
public:
    // n can be zero 
    int countSegments(string s) {
        int n = s.size();
        if(n==0)return 0;
        while(s.size()>0 && s.back()==' ')s.pop_back();
        int i=0;
        while(i<s.size() && s[i]==' ')i++;
        s=s.substr(i);
        n = s.size();
        int count = 0;
        for(int i=0;i<n;i++){
            if(i>0 && s[i]==' ' && s[i-1]!=' ')count++;
        }
        if(count==0 && s.size()>0) return 1;
        else if(count==0 && s.size()==0)return 0;
        else return count+1;

        
    }
};