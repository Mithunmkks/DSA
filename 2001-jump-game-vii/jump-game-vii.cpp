class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        if(s[n-1]=='1')return false;
        queue<int> q;
        q.push(0);
        int farthest=0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            int st = max(farthest+1,node+minJump);
            for(int i=st;i<=min(node+maxJump,n);i++){
                if(s[i]=='0'){
                    if(i==n-1)return true;
                    q.push(i);
                    
                }
            }
            farthest = node+maxJump;
        }
        return false;
    }
};