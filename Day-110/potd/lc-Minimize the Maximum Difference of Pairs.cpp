class Solution {
public:
    bool isPossible(vector<int>&nums,int p,int d){
        int n=nums.size();
        int i=0;
        int cnt=0;
        //if above condition was not there
        // while(j<n){
        //     while(i<j && abs(nums[j]-nums[i])>d) i++;
        //     int x=j-i+1;
        //     cnt+=(x*(x-1))/2;
        //     if(cnt>=p) return true;
        //     j++;
        // }
        while(i<n-1){
            int temp=abs(nums[i+1]-nums[i]);
            if(temp<=d){
                cnt++;
                i+=2;
            }else i++;
        }

        return cnt>=p;
    }
    
    int minimizeMax(vector<int>& nums, int p) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int high=(*nums.rbegin()-*nums.begin());
        int low=0;

        while(low<=high){
            int mid=low+(high-low)/2;
            if(isPossible(nums,p,mid)) high=mid-1;
            else low=mid+1;
        }

        return low;
    }
};
