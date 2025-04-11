class Solution {
public:

    bool confn(string str){
        int n=str.length();
        if(n%2)return false;
        int sum=0;
        for(int i=0;i<n/2;i++){
            sum+=((str[i]-'0')-(str[n-1-i]-'0'));
        }
        return (sum==0);
    }
    int countSymmetricIntegers(int low, int high) {
        int cnt=0;
        for(int i=low;i<=high;i++){
            if(confn(to_string(i))){
                cnt++;
            }
        }
        return cnt;
    }
};
