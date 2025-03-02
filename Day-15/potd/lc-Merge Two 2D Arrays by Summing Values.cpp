class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<vector<int>>ans;
        map<int,int>m;
        for(auto ele:nums1){
            int id=ele[0],num=ele[1];
            m[id]=num;
        }
        for(auto ele:nums2){
           int id=ele[0],num=ele[1];
           if(m.find(id)!=m.end()){
            int a=m[id];
            m[id]=a+num;
           }
           else m[id]=num;
        }
        for(auto ele:m){
            ans.push_back({ele.first,ele.second});
        }
        return ans;
    }
};
