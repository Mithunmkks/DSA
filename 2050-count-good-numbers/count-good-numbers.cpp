class Solution {
public:
    long long mod=1e9+7;
    long long power(long long a, long long b)
    {
        if(b==1)return a%mod;
        long long ans = power(a,b/2)%mod;
        if(b%2==1)
            return (a*((ans%mod)*(ans%mod))%mod)%mod;
        else return ((ans%mod)*(ans%mod))%mod;
    }
    int countGoodNumbers(long long n) {
        if(n==1) return 5;
        if(n%2==1)
        {
            return (power(4,n/2)*power(5,n/2+1))%mod;
        }
        else 
        {
            return (power(5,n/2)*power(4,n/2))%mod;

        }
    }
};