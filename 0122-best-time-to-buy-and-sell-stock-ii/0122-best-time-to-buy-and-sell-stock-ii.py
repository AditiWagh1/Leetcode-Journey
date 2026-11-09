class Solution:
    def maxProfit(self, prices: list[int]) -> int:
        totalprofit=0
        for i in range(1,len(prices)):
            if prices[i]>prices[i-1]:
                totalprofit+=prices[i]-prices[i-1]
        return totalprofit
        #optimal tc =O(N) sc=O(1) 