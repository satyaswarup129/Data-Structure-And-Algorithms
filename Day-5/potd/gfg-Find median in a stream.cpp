class Solution {
  public:
    vector<double> getMedian(vector<int> &arr) {
        // code here
        vector<double>ans;
        multimap<int,int>x;
        int n = arr.size();
        x.insert({arr[0], 1});
        auto it = x.begin();
        ans.push_back(arr[0]);
        for(int i=1; i<n; i++){
            x.insert({arr[i], 1});
            if(i%2 != 0){
                if(it->first > arr[i]) it--;
                double digit = it->first;
                it++;
                digit+=it->first;
                it--;
                ans.push_back(digit/2);
            }
            else{
                if(it->first <= arr[i])  it++;
                ans.push_back(it->first);
            }
        }
        return ans;
    }
};
