class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """

        maxStock = 0
        minValue = sys.maxsize
        
        
        for i in range(0, len(prices)):
            if(prices[i] < minValue):
                minValue = prices[i]
            else:
                maxStock = max(maxStock, prices[i] - minValue)
        
        return maxStock
        