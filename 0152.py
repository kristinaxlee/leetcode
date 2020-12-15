class Solution(object):
    def maxProduct(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        
        maxProd = nums[0];
        curMax = nums[0];
        curMin = nums[0];
        
        for i in range (1, len(nums)):
            temp = curMax
            curMax = max(nums[i], curMax * nums[i], curMin * nums[i])
            curMin = min(nums[i], temp * nums[i], curMin * nums[i])
            
            if curMax > maxProd:
                maxProd = curMax
            
        return maxProd;
        