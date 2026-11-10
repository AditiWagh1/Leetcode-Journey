class Solution:
    def hIndex(self, citations: list[int]) -> int:
        n=len(citations)
        buckets=[0]*(n+1)

        for c in citations:
            if c>=n:
                buckets[n]+=1
            else:
                buckets[c]+=1

        total_papers=0
        for h in range(n,-1,-1):
            total_papers+=buckets[h]
            if total_papers>=h:
                return h
        return 0