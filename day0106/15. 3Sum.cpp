class Solution {
public:
       
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> sol;
        vector<int> temp;
        sort(nums.begin(),nums.end());
         //corner case
            
        int k = 0,l = 0;
        
        for(int i=0;i<n-2;i++){
            //from this point onward all number will be greater than 0
            if(nums[i] > 0)
                break;
            
            //skipping the fixed number i and its combination
            //that has already appeared before 
            if(i > 0 and nums[i] == nums[i-1])continue;
            
            int s=i+1;int e=n-1;
            while(s<e){
                int x = nums[i]+nums[s]+nums[e]; 
                if(x == 0){
                    sol.push_back({nums[i], nums[s], nums[e]});
                     //skipping the second number s and e and its combination
                     //that has already appeared before 
                    int previous_start = nums[s];
                    int previous_end = nums[e];
                    while(s<e and previous_start == nums[s])s++;
                    while(s<e and previous_end == nums[e])e--;
                        
                }
                else if(x > 0){
                        e--;                    
                }
                else s++;
            }
        }
    return sol;
    }
};