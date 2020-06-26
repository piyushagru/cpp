class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if(nums.size() == 0)return {};
        sort(nums.begin(),nums.end());
        vector<int> dp(nums.size(),1);
        // int max_idx = 0;
        vector<int> previous_index(nums.size(), -1);
        for(int i = 0;i<nums.size();i++){
            for(int j = i-1;j>=0;j--){
                if(nums[i]%nums[j]==0 and dp[i] < dp[j] + 1) {
                   // dp[i] = max(dp[i],dp[j]+1);
                    dp[i] = dp[j]+1;
                   previous_index[i] = j;
               }
            }
           //  if(dp[i] > dp[max_idx]) {
           //     max_idx = i;
           // }
                }
            
    int max_idx = max_element(dp.begin(), dp.end()) - dp.begin();
        cout<<max_idx;
                vector<int> sol;
        
                
                // int val = dp[max_idx];
                // int temp = nums[max_idx];
                // for(int i = max_idx; i>=0;i--){
                //     if(temp % nums[max_idx] == 0 && val == dp[i]){
                //         sol.push_back(nums[i]);
                //         val--;
                //         temp = nums[i];
                //     }}

      int t = max_idx;  
      while(t >= 0) {
          sol.push_back(nums[t]);
          t = previous_index[t];
      }
        
    return sol;
    }
};