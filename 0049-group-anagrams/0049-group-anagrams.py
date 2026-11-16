class Solution:
    def groupAnagrams(self, strs: list[str]) -> list[list[str]]:
        mp=defaultdict(list)
        for words in strs:
            key=tuple(sorted(words))
            mp[key].append(words)

        return list(mp.values())