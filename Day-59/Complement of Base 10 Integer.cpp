class Solution {
public:
    int bitwiseComplement(int n) {
        unsigned int b=0,k=0;
        while(k<=n)b++,k=pow(2,b);
        return (k-1)^n;
    }
};
