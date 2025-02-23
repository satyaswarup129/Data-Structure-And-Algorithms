class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> s;
        bool f=0;
        for(int i : nums){
            if(i==-2147483648) f=1;
            s.insert(i);
        }
        for(int i : s) cout<<i<<" ";

        if(s.size()==2){
            int a=INT_MIN;
            for(int i : s) a=i;
            return a;
        }

        int mx1=INT_MIN, mx2=INT_MIN, mx3=INT_MIN;
        for(int i : s){
            if(i>mx1){
                mx3=mx2; mx2=mx1; mx1=i;
            }
            else if(i<mx1 and i>mx2){
                mx3=mx2; mx2=i;
            }
            else if(i<mx2 and i>mx3) mx3=i;
        }

        if(mx3==-2147483648 and f==0) return mx1;
        return mx3; 
    }
};
