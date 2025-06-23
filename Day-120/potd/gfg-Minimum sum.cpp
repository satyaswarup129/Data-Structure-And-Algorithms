class Solution {
  public:
    string minSum(vector<int> &arr) {
        if(arr.size()==2)return to_string(arr[0]+arr[1]);
        int c=0;
        string ans="";
        sort(arr.begin(),arr.end());
        for(int i=arr.size()-1;i>=0;i-=2)
        {
            int u=arr[i]+c;
            if(i-1>=0)u+=arr[i-1];
            if(u>9)
            {
                c=u/10;
                u=u%10;
            }
            else c=0;
            ans+=to_string(u);
        }
        reverse(ans.begin(),ans.end());
        int i=0;
        while(ans[i]=='0'&&i<ans.length())i++;
        return ans.substr(i,ans.length()-i+1);
    }
};
