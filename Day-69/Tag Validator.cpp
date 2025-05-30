class Solution {
public:
  bool isValid(string code){
    string s;
    for(int i = 0; i != code.size(); i++)
      if(code[i] == '<' && code[i+1] == '!' ){
        string t = "";
        for(int j = i+2; j < code.size() && t.size() != 7; j++) t += code[j];
        if(t == "[CDATA[" || t == "[cdata["){
          for(i+=7; i != code.size(); i++)
            if(code[i-2] == ']' && code[i-1] == ']' && code[i]  == '>') goto mark;
        }
        return false;
        mark:;
        s += '#';
      }
      else s.push_back(code[i]);
      
      if(s.empty() || s[0] != '<') return false; 
   
      stack<string>st;
      int k = 0, n = 0;
      for(int i = 0; i != s.size(); i++)
        if(s[i] == '<'){
          string t = "";
          n = 0;
          if(i == s.size()) return false;
          
          if(s[i+1] == '/'){
            for(i += 2; ;i++){
              if(i == s.size()) return false;
              if(s[i] == '>') break;
              if( !(s[i] >= 'A' && s[i] <= 'Z')) return false;
              t += s[i];
              if(t.size() == 10) return false;
            }
              
            if(st.empty() || st.top() != t) return false;  
            st.pop();
          }
          else{
            for(++i; ;i++){
              if(i == s.size()) return false;
              if(s[i] == '>') break;
              if( !(s[i] >= 'A' && s[i] <= 'Z')) return false;
              t += s[i];
              if(t.size() == 10) return false;
            }
            
            if(t == "" || (st.empty() && ++k == 2)) return false;
            st.push(t);
          }
        
        }else n = 1;
      
    return st.empty() && !n;
  }
};
