class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
      vector<int> res;
      for(int i : nums){
          if(i%2==0)
          res.push_back(i);
      }
      for(int j : nums){
          if(j%2!=0)
          res.push_back(j);
      }
      return res;  
    }
};