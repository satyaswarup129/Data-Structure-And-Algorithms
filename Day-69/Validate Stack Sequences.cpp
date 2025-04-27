class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int n=pushed.size();
        int i=0,j=0;
        while(i<n && j<n){
            if(st.empty()){
                st.push(pushed[i]);
                i++;
            }
            else if(st.top()==popped[j]){
                st.pop();
                j++;
            }
            else if(st.top()!=popped[j]){
                st.push(pushed[i]);
                i++;
            }
        }
        while(j<n){
            if(st.top()==popped[j]){
                st.pop();
                j++;
            }else return false;
        }
        return true;
    }
};
