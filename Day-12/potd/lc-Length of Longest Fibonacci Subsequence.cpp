class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        map<int,int>mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]=i;
        }
        int ans=0;
        for(int i=0;i<arr.size();i++){
            for(int j=i+1;j<arr.size();j++){
                long long x=arr[i];
                long long y=arr[j];
                int count=2;
                while(mp.count(x+y)){
                    long long temp=x+y;
                    x=y;
                    y=temp;   
                    count++;
                }
                if(count!=2)ans=max(count,ans);
            }
        }
        return ans;
    }
};
