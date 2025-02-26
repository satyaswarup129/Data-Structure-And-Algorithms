vector<int> findSmaller(vector<int>& arr, bool findNext) {
        int n = arr.size();
        stack<int> st;
        vector<int> res(n);
        
        int start = findNext ? n - 1 : 0;
        int end = findNext ? -1 : n;
        int step = findNext ? -1 : 1;
        int defaultValue = findNext ? n : -1;
        
        for (int i = start; i != end; i += step) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            res[i] = st.empty() ? defaultValue : st.top();
            st.push(i);
        }
        
        return res;
    }
    
    vector<int> maxOfMins(vector<int>& arr) {
        // Your code here
        int n=arr.size();
        vector<int> nextSmaller = findSmaller(arr, true);
        vector<int> prevSmaller = findSmaller(arr, false);
        vector<int>ans(n,0);
        
        for(int i=0;i<n;i++){
            int wSize=nextSmaller[i]-prevSmaller[i]-1;
            ans[wSize-1]=max(ans[wSize-1],arr[i]);
        }
        
        for(int i=n-2;i>=0;i--){
            ans[i]=max(ans[i],ans[i+1]);
        }
        
        return ans;
    }
