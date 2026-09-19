class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> need(128,0);
        for(char ch:t) need[ch]++;
        int required=t.size();
        int left=0;
        int minlen=INT_MAX;
        int beststart=0;
        for(int right=0;right<s.size();right++)
        {
            if(need[s[right]]>0)   required--;
            need[s[right]]--;
            while(required==0)
            {
                if(right-left+1<minlen)
                {
                    minlen=right-left+1;
                    beststart=left;
                }
                need[s[left]]++;
                if(need[s[left]]>0)
                {
                    required++;
                }
                left++;
            }

        }
        if(minlen==INT_MAX)
        {
            return "";
        }
        else{
            return s.substr(beststart,minlen);
        }
    }
};