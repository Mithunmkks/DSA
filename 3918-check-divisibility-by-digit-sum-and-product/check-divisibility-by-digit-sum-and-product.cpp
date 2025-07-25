class Solution {
public:
    bool checkDivisibility(int n) {
        int x = n;
        long long int a=0,b=1;
        while(n)
        {
            int rem = n%10;
            n/=10;
            a+=rem;
            b*=rem;
        }
        if(x%(a+b)==0)return true;
        else return false;
    }
};