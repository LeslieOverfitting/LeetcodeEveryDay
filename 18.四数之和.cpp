class Solution {
public:
    // vector<vector<int>> fourSum(vector<int>& nums, int target) {
    //     sort(nums.begin(), nums.end());
    //     vector<vector<int>> ans;
    //     if(nums.size() < 4)
    //         return ans;
    //     for(int i = 0; i < nums.size() - 3; ){
    //         for(int j = i + 1; j < nums.size() - 2; ){
    //             int left = j + 1;
    //             int right = nums.size() - 1;
    //             long long pre_temp = nums[i] + nums[j];
    //             while(left < right){
    //                 long long temp = nums[left] + nums[right];
    //                 temp += pre_temp;
    //                 if(temp == target){
    //                     vector<int> temp_ans;
    //                     temp_ans.push_back(nums[i]);
    //                     temp_ans.push_back(nums[j]);
    //                     temp_ans.push_back(nums[left]);
    //                     temp_ans.push_back(nums[right]);
    //                     ans.push_back(temp_ans);
    //                     left++;
    //                     right--;
    //                     while(left < right && nums[left] == nums[left - 1]){
    //                         left++;
    //                     }
    //                     while(left < right && nums[right] == nums[right + 1]){
    //                         right--;
    //                     }
    //                 }else if(temp > target){
    //                     right--;
    //                     while(left < right && nums[right] == nums[right + 1]){
    //                         right--;
    //                     }
    //                 }else{
    //                     left++;
    //                     while(left < right && nums[left] == nums[left - 1]){
    //                         left++;
    //                     }
    //                 }
    //             }
    //             j++;
    //             while(j < nums.size() - 2 && nums[j] == nums[j-1]){
    //                 j++;
    //             }
    //         }
    //         i++;
    //         while(i < nums.size() - 1 && nums[i] == nums[i-1]){
    //                 i++;
    //         }
    //     }
    //     return ans;
    // }
};