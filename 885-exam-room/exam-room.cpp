class ExamRoom {
public:
    int n;
    set<int> st;
    ExamRoom(int n) {
        this->n=n;
    }
    
    int seat() {
        if(st.empty()){
            st.insert(0);
            return 0;
        }
        int prev = -1;
        int maxiDist = -1;
        int candidate = 0;
        auto it = st.begin();
        if(*it!=0){
            maxiDist = *it;
            candidate = 0;
        }

        for(int sit:st){
            if(prev !=-1){
                int dist = (sit-prev)/2;
                if(dist>maxiDist){
                    maxiDist = dist;
                    candidate = prev+dist;
                }
            }
            prev=sit;
        }

        if(*st.rbegin() !=n-1){
            int dist = n-1 - *st.rbegin();
            if(dist > maxiDist){
                candidate = n-1;
            }
        }
        st.insert(candidate);
        return candidate;
    }
    
    void leave(int p) {
        st.erase(p);
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(n);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */