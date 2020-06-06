class Solution {
public:
	int deleteAndEarn(vector<int>& nums) {
        if(nums.size()==0) return 0;
        int MAX = *max_element(nums.begin(),nums.end());
        vector<int> points(MAX+1, 0);
        for(int i=0;i<nums.size();i++)
            points[nums[i]] += nums[i];
        
        int n = points.size();
        vector<int> dp(n,0);
        dp[0] = 0;
        dp[1] = points[1];
        for(int i=2;i<n;i++){
            dp[i] = max(dp[i-1], points[i]+dp[i-2] );
        }
    return max(dp[n-1],dp[n-2]);
    }
};