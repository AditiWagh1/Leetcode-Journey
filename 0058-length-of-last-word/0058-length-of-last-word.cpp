class Solution {
public:
    int lengthOfLastWord(string s) {
        reverse(s.begin(),s.end());
        int i=0;
        int length=0;
        while(i<s.length() && s[i]==' ')
        {
            i++;
        }
        while(i<s.length() && s[i]!=' ')
        {
            length++;
            i++;
        }
        return length;
    }
};