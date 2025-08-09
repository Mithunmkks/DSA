class Solution {
public:
    string getHint(string secret, string guess) {
        map<char,int> mapOfChars;
        for(int i=0;i<guess.size();i++){
            mapOfChars[guess[i]]++;
        }
        int x =0;
        int y=0;
        for(int i=0;i<secret.size();i++){
            if(secret[i]==guess[i]){
                x++;
                mapOfChars[guess[i]]--;
                if(mapOfChars[guess[i]]==0)mapOfChars.erase(guess[i]);
            }
        }
        for(int i=0;i<secret.size();i++){
            char ch = secret[i];
            if(secret[i]!=guess[i] &&  mapOfChars.find(ch)!=mapOfChars.end()){
                y++;
                mapOfChars[ch]--;
                if(mapOfChars[ch]==0)mapOfChars.erase(ch);
            }
        }
        string ans = "";
        ans+=to_string(x);
        ans+="A";
        ans+=to_string(y);
        ans+="B";
        return ans;

    }
};