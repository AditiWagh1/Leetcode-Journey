class Solution:
    def longestCommonPrefix(self, strs: list[str]) -> str:
        if not strs:
            return ""
        prefix=[]
        for chars in zip(*strs):
            if len(set(chars))==1:
                prefix.append(chars[0])
            else:
                break
        return "".join(prefix)

        # if not strs: #Time:O(N.MlogN) due to sorting.Space:O(1) or O(M) depending on the sort implementation.
        #     return ""
        # strs.sort()
        # first,last=strs[0],strs[-1]
        # result=[]
        # for c1,c2 in zip(first,last):
        #     if c1!=c2:
        #         break
        #     result.append(c1)
        # return "".join(result)