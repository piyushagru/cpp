class Solution {
public:
    string arrangeWords(string text) {
        vector<string> s;
        stringstream ss(text);
        string token;
        while(getline(ss,token,' ')){
            token[0] = tolower(token[0]);
           s.push_back(token); 
        }
        stable_sort(s.begin(),s.end(),[](const string &a,const string &b){
         return a.size() < b.size();
        });
        string ans = "";
        for(auto x:s){
            ans += x+" ";
        }
        ans[0] = toupper(ans[0]);
        ans.pop_back();
        return ans;
    }
};