class FindSumPairs {
public:
vector<int>arr1,arr2;
unordered_map<int,int>mp;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        arr1=nums1,arr2=nums2;
        for(auto &val:arr2)
        {
            mp[val]+=1;
        }
    }
    
    void add(int index, int val) {
        mp[arr2[index]]-=1;
        arr2[index]+=val;
        mp[arr2[index]]+=1;
    }
    
    int count(int tot) {
        int ans=0;
        for(auto &val:arr1)
        {
            ans+=mp[tot-val]*1;
        }
        return ans;
    }
};
