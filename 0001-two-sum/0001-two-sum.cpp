class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       int i=0,j=1;
       while(i<j){
           if(nums[i] + nums[j] == target){
               return {i,j};
               break;
           }
           else if(j==nums.size()-1)
           {
               i++;
               j=i+1;
           }
           else{
               j++;
           }
       }
       return {};
    }
};