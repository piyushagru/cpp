class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s == ""){
            return true;
        }
        int idx = 0;
        for(int i = 0; i<t.size();i++){
            cout<<t[i]<<":t_s:"<<s[idx]<<endl;
            if(t[i] == s[idx]){ 
                idx++;
            }
        }
        if(idx >= s.size()){
            return true;
        }
    return false;
    }
};