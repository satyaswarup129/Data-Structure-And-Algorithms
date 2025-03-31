class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
        for(char c : s){
            if(c==']'){
                string sub = "";
                while(!st.empty() && !isdigit(st.top())){
                    sub.push_back(st.top());
                    st.pop();
                    if(st.top()=='['){
                        st.pop();
                    }
                }
                string num = "";
                while(!st.empty() && isdigit(st.top())){
                    num.push_back(st.top());
                    st.pop();
                    if(!st.empty() && st.top()=='['){
                        st.pop();
                        break;
                    }
                }
                reverse(num.begin(), num.end());
                cout << num << endl;
                int n = stoi(num);
                reverse(sub.begin(), sub.end());
                while(n--){
                    for(char ch : sub){
                        st.push(ch);
                    }
                }
            }
            else st.push(c);
        }   
        string ans = "";
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
