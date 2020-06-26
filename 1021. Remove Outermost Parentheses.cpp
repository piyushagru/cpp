//25 june easy -> problem happened with the useage of erase function
class Solution {
public:
    string removeOuterParentheses(string S) {
        int op = 0;
        int cl = 0;
        string ans="";
        for(auto x:S){
            if(x == '('){
                op++;
                if(op == 1 and cl == 0)
                    continue;
                else ans = ans + x;
            }
            if(x == ')'){
                cl++;
                if(cl == op){
                    cl = 0;
                    op = 0;
                    continue;
                }                   
                else ans = ans + x;  
            }
        }
        return ans;
    }
};