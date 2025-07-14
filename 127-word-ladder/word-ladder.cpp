class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> st;
        for(auto s:wordList)st.insert(s);

        queue<pair<string,int>>q;
        q.push({beginWord,1});

        while(!q.empty())
        {
            auto it = q.front();
            q.pop();

            string word = it.first;
            
            int count = it.second;
            if(word==endWord)return count;

            for(int i=0;i<word.size();i++)
            {
                char org = word[i];
                for(char x = 'a';x<='z';x++)
                {
                    word[i]=x;
                    if(st.find(word)!=st.end())
                    {
                        q.push({word,count+1});
                        st.erase(word);
                    }
                   
                }
                word[i]=org;
            }

            
        }
        return 0;

        
    }
};