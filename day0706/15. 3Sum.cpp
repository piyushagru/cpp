class Solution {
public:
       
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        set<vector<int> > sol;
        sort(nums.begin(),nums.end());
         //corner case
            
        int k = 0,l = 0;
        
        for(int i=0;i<n-2;i++){
            //from this point onward all number will be greater than 0
            if(nums[i] > 0)
                break;
            if(i > 0 and nums[i] == nums[i-1])continue;
            
            int s=i+1;int e=n-1;
            while(s<e){
                int x = nums[i]+nums[s]+nums[e]; 
                if(x == 0){
                    sol.insert({nums[i], nums[s], nums[e]});
                    
                }
                else if(x > 0){
                        e--;                    
                }
                else s++;
            }
        }
        
        vector<vector<int> > sol1;
        for(auto it = 0;it <= sol.size();it++){
            cout<<sol[it];
        }
        for(auto it = sol.begin();it != sol.end();it++){
            cout<<it;
        }
        
        
    return sol1;
    }
};