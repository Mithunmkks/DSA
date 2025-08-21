class Solution {
public:
    bool equalFrequency(string word) {
        int a[26]={0};
        for(auto &ch:word)a[ch-'a']++;
        for(int i=0;i<26;i++){
            if(a[i]==0)continue;
            a[i]--;
            int f = 0;
            bool ok = true;
            for(int j=0;j<26;j++){
                if(a[j]==0)continue;
                if(f==0)f=a[j];
                if(a[j]!=f)ok=false;
            }
            if(ok)return true;
            a[i]++;
        }
        return false;
        
    }
};