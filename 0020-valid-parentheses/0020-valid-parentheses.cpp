class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char c: s)
        {
            if(c=='{'|| c=='(' || c=='[')
            {
                st.push(c);
            }
            else{
                if(st.empty())  return false;
                int top=st.top();
                if(c==')' && top!='('||c=='}' && top!='{'|| c==']' && top!='[')
                {
                    return false;
                }
                st.pop();
            }
        }
        return st.empty();//Only return true if the stack is empty!
    }
};