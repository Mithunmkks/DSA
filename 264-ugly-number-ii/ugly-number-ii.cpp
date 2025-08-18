class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long long ,vector<long long >,greater<long long>> pq;
        long long  num = 0;
        set<long long > seen;
        seen.insert(1);
        pq.push(1);
        long long  v[] = {2,3,5};
        for(int i=1;i<=n;i++){
            num = pq.top();
            pq.pop();
            for(auto f:v){
                if(seen.find(f*num)==seen.end()){
                    seen.insert(f*num);
                    pq.push(f*num);
                }
            }
        }
        return num;
    }
};