class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int maxProd = nums[0];
        int curMax = nums[0];
        int curMin = nums[0];
        
        for(int i=1; i<nums.size(); i++) {
            int temp = curMax;
            int tempCurMax = max(nums[i], curMax * nums[i]);
            curMax = max(tempCurMax, curMin * nums[i]);
            
            int tempCurMin = min(nums[i], temp * nums[i]);
            curMin = min(tempCurMin, curMin * nums[i]);
            
            if(curMax > maxProd) {
                maxProd = curMax;
            }
            
        }
        
        return maxProd;
    }
};