
// User function Template for C++

class Solution {
  public:
  double fact(int n){
      if(n==0){
          return 1;
      }
      return n*fact(n-1);
  }
    int nCr(int n, int r) {
        // code here
        if(r>n){
            return 0;
        }
        double  numerator=fact(n);
        double  denominator=fact(r);
        double  help=fact(n-r);
        return (int)(numerator/(denominator*help)+0.5);
    }
};
