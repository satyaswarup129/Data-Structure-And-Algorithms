class Solution {
  public:
    string longestString(vector<string> &words) {
        // code here
        string ans = "";
        int len = 0;
        
        sort(words.begin(), words.end());
        
        unordered_map<string, bool> um;

        
        for(auto z: words){
          int l= z.size();
            if(l==1){
                if(l>len){
                    len = l;
                    ans = z;
                    
                }
                um[z]=true;
            }
            else{
                string p = z;
                p.pop_back();
                
                if(um.find(p)!=um.end()){
                    if(l>len){
                        len= l;
                        ans = z;
                    }
                    um[z]= true;
                }
                
                
            }
        }
        
        return ans;
    }
};
