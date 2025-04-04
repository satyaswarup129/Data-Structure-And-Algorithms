#include <string>
class Solution {
public:
    string freqAlphabets(string s) {
        string str="";
        for(int i=0;i<s.size();i++){
            if((i+2)<s.size() && s[i+2]=='#'){
                int temp = stoi(s.substr(i,i+2))-10;
                char c= 'j'+temp;
                str=str+c;
                i=i+2;
            }
            else{
                int temp = s[i]-'1';
                char c = 'a'+temp;
                str=str+c;
            }
        }
    return str;
    }
};
