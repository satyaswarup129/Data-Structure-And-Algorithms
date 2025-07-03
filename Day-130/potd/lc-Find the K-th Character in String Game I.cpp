class Solution {
public:
string f(string s,int k ){
    if(s.size()>=k) return s;
    string temp=s;
    for(auto it:s){
        temp.push_back(((it - 'a' + 1) % 26 + 'a' ));
    }
    return f(temp,k);
}
    char kthCharacter(int k) {
        string s=f("a",k);
        return s[k-1];
    }
};
