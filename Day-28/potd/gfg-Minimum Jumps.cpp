class Solution {
  public:
    int minJumps(vector<int>& arr) {
        int ans=0,max_ind=0,ind=0;
        for(int i=0;i<(int)arr.size();i++){
            if(i>ind){
                if(max_ind<i) return -1;
                ind=max_ind;
                ans++;
            }
            max_ind=max(max_ind,i+arr[i]);
        }
        return ans;
    }
};
