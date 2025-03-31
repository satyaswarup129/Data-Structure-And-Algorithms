class Solution {
  public:
     int maxPartitions(string &s) {
        // code here
        vector<vector<int>> mat(26,vector<int>(2));
        for(int i=0;i<26;i++){
            mat[i][0]=INT_MAX;
            mat[i][1]=INT_MIN;

        }
        for(int i=0;i<s.length();i++){
            int t=s[i]-'a';
            mat[t][0]= min(mat[t][0],i);
            mat[t][1]= max(mat[t][1],i);
        }
        vector<pair<int,int>> vp;
        for(vector<int> t:mat){
            if(t[0]!=INT_MAX){
                vp.push_back({t[0],t[1]});
            }
        }
        sort(vp.begin(),vp.end());
        int start=vp[0].first;
        int end=vp[0].second;
        vector<int> ans;

        for(int i=0;i<vp.size();i++){
            if(vp[i].first<=end){
                end =max(end,vp[i].second);
            }
            else{
                ans.push_back(end-start+1);
                start=vp[i].first;
                end=vp[i].second;
                        }            
                        }
        ans.push_back(end-start+1);
        return ans.size();
    }


};
