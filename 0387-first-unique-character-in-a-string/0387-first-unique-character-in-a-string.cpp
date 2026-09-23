class Solution {
public:
    int firstUniqChar(string s) {
       queue<int> q;
       unordered_map<char,int> mp;
        for(int i=0;i<s.size();i++)
        {
            //if curr char appears for first time push it's index in queue
            if(mp.find(s[i])==mp.end())
            {
                q.push(i);
            }
            //update char freq in map
            mp[s[i]]++;
            while(q.size()>0 && mp[s[q.front()]]>1)
            {
                q.pop();
            }
        }
        return q.empty()?-1:q.front();
    }
};//tc=O(n) and sc=O(n)

//optimal approach TC=O(n) sc=O(1)
// int firstUniqCharOptimal(string s) {
//     int freq[26] = {0};

//     // Pass 1: populate counts
//     for (char ch : s) {
//         freq[ch - 'a']++;
//     }

//     // Pass 2: first char with count == 1
//     for (int i = 0; i < s.size(); i++) {
//         if (freq[s[i] - 'a'] == 1) {
//             return i;
//         }
//     }

//     return -1;
// }