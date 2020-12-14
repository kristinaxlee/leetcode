class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        if(nums.size() == 1) {
            return nums[0];
        }
        
        vector<int> sums;
        sums.push_back(nums[0]);
        int maxSum = nums[0];
        
        
        for(int i=1; i<nums.size(); i++) {
            if(sums[i-1] + nums[i] > nums[i]) {
                sums.push_back(sums[i-1] + nums[i]);
            }
            else {
                sums.push_back(nums[i]);
            }
            
            maxSum = max(maxSum, sums[i]);
        }
        
        
        return maxSum;
    }
};