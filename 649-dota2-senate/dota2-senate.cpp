class Solution {
public:
    string predictPartyVictory(string senate) {
        deque<int> qd;
        deque<int> qr;
        int n = senate.size();
        for(int i=0;i<n;i++){
            if(senate[i]=='R')qr.push_back(i);
            else qd.push_back(i);
        }

        while(!qd.empty() && !qr.empty()){
            if(qr.front()<qd.front()){
                qd.pop_front();
                int pos = qr.front();
                qr.pop_front();
                qr.push_back(pos+n);
            }
            else{
                qr.pop_front();
                int pos = qd.front();
                qd.pop_front();
                qd.push_back(pos+n);
            }
        }
        if(qr.size()>0)return  "Radiant";
        else return "Dire";


        
    }
};