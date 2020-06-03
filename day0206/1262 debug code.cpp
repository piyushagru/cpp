/*
Reference for DP

    A Tutorial on TopCoder: Dynamic Programming: From novice to advanced
    https://www.topcoder.com/community/competitive-programming/tutorials/dynamic-programming-from-novice-to-advanced/
    Dynamic Programming - A Computational Tool by Prof. Art Lew and Dr. Holger Mauch
    Dynamic Programming - Foundations and Principles by Moshe Sniedovich


    debug code
    https://ide.codingblocks.com/s/248703


*/

#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int> nums;
    for(int i=0;i<5;i++){
        int val = 0;
        cin>>val;
        nums.push_back(val);
    }
vector<int> dp(3,0);
vector<int> dp2(3);

    for(int i=0; i<nums.size(); i++){
            dp2=dp;
            for(int j=0; j<3; j++){
                int x = nums[i];
                dp[(dp2[j]+x)%3]=max(dp[(dp2[j]+x)%3], dp2[j]+x);
                cout<<"dp["<<(dp2[j]+x)%3<<"] = max(dp["<<(dp2[j]+x)%3<<"],"<<dp2[j]+x<<");"<<endl;
                
        
                
                // int x = nums[i];
                // dp2[0] = max( dp[x%3] + x , dp[0] );
                // dp2[1] = max( dp[(x+1)%3] + x , dp[1] );
                // dp2[2] = max( dp[(x+2)%3] + x , dp[2] );
                // dp = dp2;
                cout<<"x : "<<nums[i]<<endl;
                
                cout<<"dp[0]: "<<dp[0]; cout<<"     dp2[0]: "<<dp2[0]<<endl;
                cout<<"dp[1]: "<<dp[1]; cout<<"     dp2[1]: "<<dp2[1]<<endl;
                cout<<"dp[2]: "<<dp[2]; cout<<"     dp2[2]: "<<dp2[2]<<endl;}

    }
    cout<<"answer: "<<dp[0];
}