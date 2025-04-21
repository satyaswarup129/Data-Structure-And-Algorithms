class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        int n = arr.size();

        stack<int> st;
        vector<int> nse(n, n);
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                nse[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        while (!st.empty())
            st.pop();

        vector<int> pse(n, -1);
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                pse[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        int maxArea = 0;
        for(int i = 0 ; i < arr.size() ; i++){
            int area = (arr[i] * (nse[i] - pse[i] - 1));
            maxArea = max(area, maxArea);
        }
        return maxArea;
    }
};
