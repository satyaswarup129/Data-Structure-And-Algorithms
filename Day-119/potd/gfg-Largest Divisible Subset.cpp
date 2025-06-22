class Solution {
  public:
    vector<int> ans;
    void find(vector<int>& arr,int ind,int prev, vector<int> tmp){
        //not take
        if(ind==arr.size()){
            if(tmp.size()>ans.size())
            ans=tmp;
            if(tmp.size()==ans.size() && tmp>ans)
            ans=tmp;
            return;
        }
        find(arr,ind+1,prev,tmp);
        //take
        if(arr[ind]%prev==0){
            
            tmp.push_back(arr[ind]);
            find(arr,ind+1,arr[ind],tmp);
            
        }
        
    }
    vector<int> largestSubset(vector<int>& arr) {
        // Code here
        sort(arr.begin(),arr.end());
        
        find(arr,0,1,ans);
        return ans;
        
    }
};
