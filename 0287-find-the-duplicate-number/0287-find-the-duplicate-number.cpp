class Solution {
public:
    int findDuplicate(std::vector<int>& nums) {
        std::unordered_set<int> res;
        for (int num : nums) {
            if (res.find(num) != res.end()) {
                return num;
            }
            res.insert(num);
        }
        return -1;  
    }
};