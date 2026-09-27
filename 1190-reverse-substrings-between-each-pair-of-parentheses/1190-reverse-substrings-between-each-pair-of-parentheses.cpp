class Solution {
public:
    string reverseParentheses(string s) {
        string ans = "";

        stack<char> st;

        for(int i=0; i<s.size(); i++){
            if(s[i] == ')'){
                string t = "";
                while(st.top() != '('){
                    t += st.top(); st.pop();
                }
                st.pop();
                for(auto it : t) st.push(it);
            }
            else{
                st.push(s[i]);
            }
        }
        while(!st.empty()){
            ans += st.top(); st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};