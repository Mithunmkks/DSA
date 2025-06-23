class Solution {
public:
    bool is_pal(string s) {
        if (s.size() <= 1)
            return true;
        int i = 0, j = s.size() - 1;
        while (i < j) {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    string kbn(long long n, long long  k) {
        if (n == 0)
            return "";

           
        return kbn(n / k, k) + char('0' + (n % k));
    }
    long long kMirror(int k, int n) {
        long long ans = 0;
        long long  l = 1; 
        while(n>0)
        {
            long long  hl = (l+1)/2;
            long long mini = pow(10,hl-1);
            long long maxi = pow(10,hl)-1;
            for(long long  i=mini;i<=maxi;i++)
            {
                string  s1 = to_string(i);
                string  s2=s1;
                reverse(begin(s2),end(s2));
                string num;
                if(l%2==0)num=s1+s2;
                else num = s1+s2.substr(1);

                long long knum = stoll(num);
                string sknum = kbn(knum,k);
                if(is_pal(num) && is_pal(sknum))
                {
                    ans+=knum;
                    n--;
                    if(n==0)break;
                }
                
            }
            l++;
        }
        return ans;

    }
};