class Solution:
    def isValid(self, s: str) -> bool:
        st=[]
        mapping={')':'(',']':'[','}':'{'}
        for ch in s:
            if ch in mapping:#closing bracket
                if not st or st[-1]!=mapping[ch]:
                    return False
                st.pop()
            else:#opening bracket
                st.append(ch)
        return len(st)==0
