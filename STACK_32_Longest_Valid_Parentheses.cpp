// https://leetcode.com/problems/longest-valid-parentheses/description/
// 32. Longest Valid Parentheses

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);
        int maxlen = 0;

        for(int i = 0; i < s.length(); i++){
            if(s[i] == '('){
                st.push(i);
            } else {
                st.pop();
                if(st.empty()){
                    st.push(i);
                } else {
                    maxlen = max(maxlen, i-st.top());
                }
            }
        }
        return maxlen;
    }
};
