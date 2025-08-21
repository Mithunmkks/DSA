class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.size();
        for(int i=0;i<n;i+=2*k){
            int j = min(n-1,i+k-1);
            reverse(s.begin()+i,s.begin()+j+1);
        }
        return s;
        
    }
};