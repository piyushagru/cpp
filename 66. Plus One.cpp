//27 june
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
            int i = digits.size()-1;
            while(i>=0 and digits[i] == 9){
                i--;
            }
        if(i == -1){
            vector<int> ans(digits.size()+1,0);
            ans[0] = 1;
            return ans;
        }
             digits[i++] += 1;
            while(i<digits.size()){
                digits[i] = 0;
                i++;
            }
        return digits;      
    }
};