class Solution {
public:
    int gcd(int a,int b){
        if(a==0)return b;
        return gcd(b%a,a);
    }
    bool hasGroupsSizeX(vector<int>& deck) {
        map<int,int> mp;
        for(auto i:deck){
            mp[i]++;
        }
        int ans = 0 ;
        for(auto i:mp){
            if(i.second==1)return false;
            ans=gcd(ans,i.second);
        }
        return ans!=1;
    }
};