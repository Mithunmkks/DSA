class Solution {
public:
    string addStrings(string num1, string num2) {
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        int n = num1.size();
        int m = num2.size();
        int i=0,j=0;
        int carry = 0;
        string ans ="";

        // 11i
        // 12j3


        while(i<n && j<m){
            int num = (num1[i]-'0') + (num2[j]-'0') + carry;
            carry=(num/10);
            num = num%10;
            ans=to_string(num)+ans;
            i++;
            j++;
        }
        cout<<ans;
        while(i<n){
            int num = (num1[i]-'0') + carry;
            carry=(num/10);
            num = num%10;
            ans=to_string(num)+ans;
            i++;
        }
        while(j<m){
            int num = (num2[j]-'0') + carry;
            carry=(num/10);
            num=num%10;
            ans=to_string(num)+ans;
            j++;
        }
        if(carry>0){
            ans=to_string(carry)+ans;
        }
        return ans;

    }
};