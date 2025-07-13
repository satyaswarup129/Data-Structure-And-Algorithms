class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& p, vector<int>& t) {
        int ans=0;
        sort(p.begin(),p.end());
        sort(t.begin(),t.end());
        int i=0;
        int j=0;
        int n=p.size();
        int x=t.size();
        while(i<n and j<x){
            if(p[i]<=t[j]){
                ans++;
                i++;
                j++;
            }else{
                j++;
            }
        }
        return ans;
    }
};
