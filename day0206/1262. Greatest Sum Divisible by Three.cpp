/*
Reference for DP

    A Tutorial on TopCoder: Dynamic Programming: From novice to advanced
    https://www.topcoder.com/community/competitive-programming/tutorials/dynamic-programming-from-novice-to-advanced/
    Dynamic Programming - A Computational Tool by Prof. Art Lew and Dr. Holger Mauch
    Dynamic Programming - Foundations and Principles by Moshe Sniedovich


    debug code
    https://ide.codingblocks.com/s/248703


*/

class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<int > dp(3,0),dp2;
        
        for(int i=0;i<nums.size();i++){
            dp2 = dp;
            int x = nums[i];
                for(int j = 0;j<3;j++){
                    dp[ (dp2[j]+x)%3 ] = max( dp[ (dp2[j]+x)%3 ], dp2[j]+x );
                    
                }
        }
        return dp[0];
    }
};