class Solution {
public:
    bool isVowel(char ch) {
        
        ch = tolower(ch);
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');

    }
    string reverseVowels(string s) {
        int n = s.size() ;

        int i=0, j=n-1; 

        while(i<j and i<n and j<n){
            while(i<n and !isVowel(s[i])) i++ ;
            if(i>=n) break ;
            while(j<n and !isVowel(s[j])) j-- ;
            if(j<0) break ;
            if(i<j) swap(s[i], s[j]) ;
            else  break ;
            i++;
            j--;
        }
        return s;
    }
};
