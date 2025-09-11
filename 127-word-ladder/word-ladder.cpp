class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> st(wordList.begin(),wordList.end());
        // pair<string,int> 
        queue<pair<string,int>> q;
        q.push({beginWord,0});
        while(!q.empty()){
            auto it = q.front();
            q.pop();

            string w = it.first;
            int dist = it.second;
            if(w==endWord)return dist+1;

            for(int i=0;i<w.size();i++){
                for(char x = 'a';x<='z';x++){
                    char org = w[i];
                    w[i]=x;
                    if(st.find(w)!=st.end()){
                        q.push({w,dist+1});
                        st.erase(w);
                        cout<<w<<" => ";
                    }
                    w[i]=org;
                }
            }

        }
        return 0;
    
    }
};