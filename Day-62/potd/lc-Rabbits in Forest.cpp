class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int>freq;
        for(auto it:answers){
            freq[it]++;
        }
        int ans=0;
        for(auto it:freq){
            int gps=ceil((it.second*1.0)/(it.first+1));
            cout<<gps<<" ";
            ans+=gps*(it.first+1);
        }
        return ans;
    }
};
