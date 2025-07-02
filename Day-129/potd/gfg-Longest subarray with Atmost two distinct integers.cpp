class Solution {
  public:
    int totalElements(vector<int> &arr) {
        // code here
        int left=0;
        int right=0,n=arr.size();
        unordered_map<int,int>hash;
        int ans=-1;
        while(left<n){
            while(right<n && hash.size()<=2){
                hash[arr[right]]++;
                right++;
            }
            if(hash.size()<=3){
                int x=right-left;
                if(hash.size()>2)x--;
                ans=max(ans,x);
            }
            hash[arr[left]]--;
            if(hash[arr[left]]==0)hash.erase(arr[left]);
            left++;
        }
        return ans;
    }
};

