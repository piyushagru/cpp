// 26 june
//a brute force method
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
int i=0,j=0;
        for(i =0;i<nums.size();i++){
            for(j =i+1;j<nums.size();j++){
                if(nums[i] + nums[j] == target){
                    return {i,j};
                }
            }
        }
    return {};
    }
};

//using hash map
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int,int> idx;
        for(int i = 0;i<nums.size();i++){
            if(idx.find(target - nums[i]) != idx.end())
                return {idx[target - nums[i]],i};
        idx[nums[i]] = i;
        }
    return {};
    }
};