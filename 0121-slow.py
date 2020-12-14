class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        #print "max: ", max(prices[0:])
        
        # find the max difference j-i, where the i < j
        
        maxStock = 0
        
        
        for i in range(0, len(prices)):
            profit = max(prices[i:]) - prices[i]
            maxStock = max(profit, maxStock)
        
        return maxStock
        