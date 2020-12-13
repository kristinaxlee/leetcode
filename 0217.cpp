class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        unordered_set <int> numberBank;
        
        for(int i = 0; i<nums.size(); i++) {
            if (numberBank.find(nums[i]) != numberBank.end()) {
                return true;
            }
            numberBank.insert(nums[i]);
        }
        
        return false;
    }
};