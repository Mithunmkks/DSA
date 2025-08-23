class DetectSquares {
public:
    map<vector<int>,int> mp;
    DetectSquares() {     
    }  
    void add(vector<int> point) {
       mp[point]+=1;
    }
    int count(vector<int> point) {
        int x1 = point[0];
        int y1 = point[1];
        int count = 0;
        for(auto p:mp){
            int c1 = p.second;
            int x2=p.first[0];
            int y2=p.first[1];
            if(abs(x1-x2)!=abs(y2-y1) || (x1==x2 && y2==y2) )continue;
            vector<int> v1 = {x1,y2};
            vector<int> v2 = {x2,y1};
            if(mp.find(v1)==mp.end() || mp.find(v2)==mp.end())continue;
            count+=mp[v1]*mp[v2]*c1;
        }
        return count;
    }

};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */