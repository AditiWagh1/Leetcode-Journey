class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    int left=0,maxlen=0;
    unordered_set<char> window;
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
    return maxlen; //tc=O(n) sc=O(min(n,Sigma)

    }
    // vector<int> last_seen(128,-1);
    // int left=0,maxlen=0;
    // for(int right=0;right<s.size();right++)
    // {
    //     char ch=s[right];
    //     if(last_seen[ch]>=left)
    //     {
    //         left=last_seen[ch]+1;
    //     }
    //     last_seen[ch]=right;
    //     maxlen=max(maxlen,right-left+1);
    // }
    // return maxlen;
    // } //optimal approach tc=O(n) sc=O(min(n,Sigma)
};