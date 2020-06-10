class Solution {
public:
    int targetSum;
    static vector< int > visited(1000000);
    bool canPartitionFrom(vector<int>& nums, int k, int currSum, int idx){
        int sss = nums.size();
        
        // for(auto x:visited)cout<<x<<" ";
        if(k == 1) return true; //ek bucket hi bachi hogi jo sum ko pura kar hi degi
        
        if(currSum == targetSum)
            return canPartitionFrom(nums, k-1, 0, 0);
        
        for(int i = idx; i<nums.size();i++){
            if(visited[i] == 0 and currSum + nums[i] <= targetSum){
                visited[i] = 1;
                if(canPartitionFrom(nums, k, currSum + nums[i], i+1))
                    return true;
           visited[i] = 0;//if this number did'nt work we unvisit this number
            }  
        }
    return false; //kuch bhi ni bacha toh false return kardo
    }
    
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        
        int sum = 0;
        for( int &n : nums ) sum += n;
        if(sum % k != 0)
            return false;
       
        targetSum = sum/k;
        return canPartitionFrom(nums, k, 0, 0);
    }
};