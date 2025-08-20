class Solution {
public:
    string convertToBase7(int num) {
        if(num==0)return "0";
        string ans="";
        bool isneg= num<0?true:false;
        num=abs(num);
        while(num>0){
            int x = num%7;

            ans+=to_string(x);
            num/=7;
        }
        reverse(ans.begin(),ans.end());
        if(isneg)return "-"+ans;
        else return ans;
    }
};