class Solution {
public:
    bool canJump(vector<int>& nums) {
        int last_valid_idx = nums.size()-1;
        for(int i=nums.size()-1;i>=0;i--){
            if(i + nums[i] >= last_valid_idx)
                last_valid_idx = i;
        }
    return last_valid_idx == 0;
    }
    
};