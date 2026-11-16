class Solution:
    def firstUniqChar(self, s: str) -> int:
        q=deque()
        mp=defaultdict(int)
        for i,ch in enumerate(s):
            if ch not in mp:
                q.append(i)
            mp[ch]+=1
            while q and mp[s[q[0]]]>1:
                q.popleft()
        return q[0] if q else -1
