class Solution {
  public:
    int convert(string x){
        int i=0,num=0,s=0;
        if(x[0]=='-') s=1;
        while(i<x.length()){
            if(x[i]>='0' and x[i]<='9') num=(num*10)+(x[i]-'0');
            i++;
        }
        return s==1?num-(2*num):num;
    }
    int evaluate(vector<string>& arr) {
        stack<int> st;
        for(int i=0;i<arr.size();i++){
            if(arr[i]!="+" and arr[i]!="-" and arr[i]!="*" and arr[i]!="/") st.push(convert(arr[i]));
            else {
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                if(arr[i]=="+") st.push(b+a);
                else if(arr[i]=="-") st.push(b-a);
                else if(arr[i]=="*") st.push(b*a);
                else if(arr[i]=="/") st.push(b/a);
            }
        }
        return st.top();
    }
};
