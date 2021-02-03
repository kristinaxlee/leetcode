class Solution {
public:
    unordered_map<int, int> seen;
    // number, index
    
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> answer;
        
        for(int i=0; i<nums.size(); i++) {
            
            auto it = seen.find(target-nums[i]);
            if(it != seen.end()) {
                answer.push_back(it->second);
                answer.push_back(i);
                break;
            }
            
            seen.insert({nums[i], i});
        }
        
        return answer;
    }
};