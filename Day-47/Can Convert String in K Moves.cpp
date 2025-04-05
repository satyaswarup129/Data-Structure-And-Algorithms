class Solution {
public:
    bool canConvertString(string s, string t, int k) {
        if(s.length()!=t.length())return false;
        unordered_map<long long int,long long int>mp;
        vector<long long int>ans;
        for(int i=0;i<t.size();i++)
        {
         if(s[i]!=t[i])
         {
           long long int req = s[i]<t[i] ? t[i]-s[i] : 26+t[i]-s[i];
           if(req>k)return false;
               if(mp.find(req)!=mp.end())
               {
                 mp[req]+=26;
                 if(mp[req]>k)
                     return false;
               }
               else
               {
                     mp[req]=req;
                    if(req>k)return false;
               }
          }
        }
        return true;
    }
};
