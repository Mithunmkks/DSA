class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        bool isBlock = false;
        vector<string> ans;
        string temp;
        for (auto line : source) {
            for (int i = 0; i < line.size(); i++) {
                if (i != line.size() - 1 && line[i] == '/' &&
                    line[i + 1] == '/' && !isBlock) {
                    break;
                } else if (i != line.size() - 1 && line[i] == '/' &&
                    line[i + 1] == '*' && isBlock==false) {
                    isBlock = true;
                    i++;
                } else if (i != line.size() - 1 && line[i] == '*' &&
                           line[i + 1] == '/' && isBlock==true) {
                    isBlock = false;
                    cout<<"test"<<endl;
                    i++;
                } else if (!isBlock)
                    temp.push_back(line[i]);
            }
            if (!isBlock && temp.size() > 0) {
                ans.push_back(temp);
                cout<<temp<<endl;
                temp.clear();
            }
        }
        if(temp.size()>0)ans.push_back(temp);
        cout<<temp<<endl;
        return ans;
    }
};