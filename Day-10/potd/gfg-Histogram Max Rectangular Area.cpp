class Solution {
  public:
    int getMaxArea(vector<int> &arr) {
       stack<int> st;
       int n=arr.size();
       int maxArea=0;
       for(int i=0;i<=n;i++){
           while(!st.empty() && (i==n || arr[st.top()]>arr[i])){ //next smaller element of stack top is current element at i
               int h=arr[st.top()];
               st.pop();
               int w;
               if(st.empty()) w=i; //no previous smaller element of prev st.top()
               else w = i-st.top()-1;
               
               maxArea=max(maxArea,h*w);
           }
           
           st.push(i);
       }
       
       return maxArea;
    }
};
