//25 june easy
class Solution {
public:
    string defangIPaddr(string address) {
        string ans="";
        for(auto x: address){
            if(x == '.')
                ans = ans +"[.]";
            else ans = ans + x;
        }
    return ans;
    }
};