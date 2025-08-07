class Solution {
public:
    int reverse(int x) {
        long long num=0;
        long long fact = 10;
        long long sign = x<0?-1:1;
        while(x){

            long long rem = x%10;
            x/=10;
            num = num*fact + rem;

        }

        if(num>=INT_MIN && num<=INT_MAX)return num;
        else return 0;
    }
};