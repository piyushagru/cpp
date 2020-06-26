// we just removed the peak number from the stack.....traversing from left to right

class Solution {
public:
    string removeKdigits(string num, int k) {
        stack <char>digit;
        string ans = "";
        
        if(num.size() == 0)return "0";
        if(num.length() < k)return "0";
        digit.push(num[0]);
              
        for(int i = 1;i<num.length();i++){
            while((!digit.empty() and k>0) and num[i] < digit.top() ){
                digit.pop();
                k--; 
            }
            digit.push(num[i]);
        }
                
        while(!digit.empty()){
            ans = ans + digit.top();
            digit.pop();
        }
        // cout<<ans;
        reverse(ans.begin(),ans.end());
        
        
        if(k>0){
            ans.erase(ans.length()-k,k);
        }
        
        cout<<ans;
        while(ans[0] == '0'){
            ans.erase(0,1);
        }
        
        
        
        return ans == "" ? "0" : ans;
    }
};