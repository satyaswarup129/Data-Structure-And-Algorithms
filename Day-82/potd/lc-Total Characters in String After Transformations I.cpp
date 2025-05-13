class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        vector<int>mp(26,0);
        int m=1000000007,count=0;
        for(auto it:s)mp[it-'a']++;
        while(t--){
            vector<int>val(26,0);
            for(int i=0;i<26;i++){
                if(i==25){
                    val[0]=(val[0]+mp[i])%m;
                    val[1]=(val[1]+mp[i])%m;
                }
                else val[i+1]=(val[i+1]+mp[i])%m;
            }
            mp=val;
        }
        for(auto it:mp)
        count=(count%m+(it%m))%m;
        return count;
    }
};
