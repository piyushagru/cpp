class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int> >dp(m,vector<int> (n,grid[0][0]));
        int left = 0, up = 0;
    
        
        for(int i = 0 ;i<m; i++){
            for(int j = 0;j<n;j++){
                
                if(!i and !j)
                    {dp[i][j] = grid[i][j];
                    continue;}
                
                if(!i)
                   { dp[i][j] = dp[i][j-1] + grid[i][j];
                    continue;}
                
                if(!j)
                    {dp[i][j] = dp[i-1][j] + grid[i][j];
                    continue;}
                
                left = dp[i-1][j];
                up = dp[i][j-1];
                  
                dp[i][j] = min(left,up) + grid[i][j];
            }
        }
        
        for(int i = 0 ;i<m;i++){
            cout<<endl;
            for(int j = 0;j<n;j++){
                cout<<dp[i][j]<<" ";
            }
        }
        
    return dp[m-1][n-1];
    }
};