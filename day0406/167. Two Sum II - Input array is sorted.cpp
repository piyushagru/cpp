/*
two pointer technique oposite directional
*/


class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int s = 0;
        int e = numbers.size() - 1;
        // vector<int> ans(2);
        
        while(s<e){
            int x = numbers[s] + numbers[e];
            if(x == target){
               return {s+1,e+1};
            }
            else if(x > target){
                e--;
            }
            else s++;
        }
    return {};
    }
};