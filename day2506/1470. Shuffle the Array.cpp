// class Solution {
// public:
//     vector<int> shuffle(vector<int>& nums, int n) {
//         vector<int> ans(nums.size());
//         int k = 0;
//         for(int i = 0, j = n ;j<nums.size() and i<n;i++, j++){
//             ans[k] = nums[i];
//             ans[k+1] = nums[j];
//             k=k+2;
//         }
//         return ans;
//     }
// };

// class Solution {
// public:
//     vector<int> shuffle(vector<int>& nums, int n) {
//         vector<int> ans;
//         // int k = 0;
//         for(int i = 0;i<n;i++){
//             cout<<nums[i+n];
//             ans.push_back(nums[i]);
//             ans.push_back(nums[i+n]);
//         }
//         return ans;
//     }
// };


class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans(nums.size());
        int k = 0;
        for(int i = 0;i<n;i++){
            cout<<nums[i+n];
            ans[k++] = nums[i];
            ans[k++] = nums[i+n];
        }
        return ans;
    }
};