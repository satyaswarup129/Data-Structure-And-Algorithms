class Solution {
public:
    string decodeMessage(string key, string message) {
        unordered_map<char, char> mp;
        unordered_map<char, bool> rmp;
        
        string nkey = "", sol = "";
        
        //removing repeatency
        for(auto c: key)
           if(rmp[c] == false && c != ' '){
            rmp[c] = true;
            nkey += c;
           }
        
        //idxng
        int idx = 0;
        for(auto c: nkey){
           char ndx = idx +'a';
           mp[c] = ndx;
           idx++; 
        }

        //making string
        for(auto c: message){
            if(c == ' ') sol+= " ";
            else sol += mp[c];
        }
       return sol;  
    }
};
