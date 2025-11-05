class Solution {
public:
    double myPow(double x, int N) {
        long long n = N;
        if(x==0)return 0;
        if(x==1)return 1;
        if(n==0)return 1;
        double res = 1.0;
        if(n<0){
            n=abs(n);
            x=1.0/x;
        }
         double cur = x;
        while(n){
            if(n&1==1){
                res*=cur;
            }
            cur*=cur;
            n=n>>1;
        }
        return res;


    }
};