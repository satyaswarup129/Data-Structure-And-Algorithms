class Solution {
    bool checkIPV4(string query) {
        int len=query.size(), total=0;
        string st ="";
        for(int i=0; i<len; i++) {
            if((query[i] >='A' && query[i] <='Z') || 
            (query[i] >='a' && query[i] <='z') || query[i] ==':')
                return false;
            if(query[i] == '.') {
                if((st.length() > 1 && st[0] == '0') || 
                st.length() > 3 ||st == "") 
                    return false;
                int num = stoi(st);
                if(num > 255) return false;
                else {
                    total++;
                    st="";
                }
            }
            else {
                st+=query[i];
            }
        }
        if(total != 3 || st=="") return false;
        if((st.length() > 1 && st[0] == '0') || st.length() > 3) 
            return false;
        int num = stoi(st);
        if(num > 255) return false;
        else return true;
    }
    bool checkIPV6(string query) {
        int len=query.size(), total=0;
        string st ="";
        for(int i=0; i<len; i++) {
            if((query[i] >='G' && query[i] <='Z') || 
            (query[i] >='g' && query[i] <='z') || query[i] =='.')
                return false;
            if(query[i] == ':') {
                if(st.length() > 4 || st.length() == 0) return false;
                else {
                    st = "";
                    total++;
                }
                
            }
            else st+=query[i];
        }
        if(total != 7 || st.length() > 4 || st.length() == 0) return false;
        return true;
    }
public:
    string validIPAddress(string queryIP) {
        bool res = false;
        if(queryIP.contains(".")) {
            res = checkIPV4(queryIP);
            if(res) return "IPv4";
            else return "Neither";
        }
        else if(queryIP.contains(":")) {
            res = checkIPV6(queryIP);
            if(res) return "IPv6";
            else return "Neither";
        }
        else return "Neither";
    }
};
