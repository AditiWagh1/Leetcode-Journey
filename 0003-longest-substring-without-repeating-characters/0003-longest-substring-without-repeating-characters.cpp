class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       unordered_set<char> window;
       int left=0;
       int maxlen=0;
       for(int right=0;right<s.size();right++)
       {
        char ch=s[right];
          while(window.count(ch))
          {
            window.erase(s[left]);
            left++;
          }
          window.insert(ch);
          maxlen=max(maxlen,right-left+1);
       }
       return maxlen;
    }
};