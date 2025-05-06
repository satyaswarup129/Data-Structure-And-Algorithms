class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        reverse(nums.begin(), nums.end());
        deque<int>dq;
        int start=0;
        int end=0;
        long long reqOps=0;
        long long ans=0;
        for(;end<nums.size();end++){
            while(!dq.empty()&&nums[end]>nums[dq.back()]){
                int curr=dq.back();
                dq.pop_back();
                int next=!dq.empty()?dq.back():start-1;
                reqOps+=(long long)(nums[end]-nums[curr])*(long long)(curr-next);
            }
            //cout<<start<<" "<<end<<" "<<reqOps<<endl;
            dq.push_back(end);
            while(!dq.empty()&&reqOps>(long long)k){
                reqOps-=(long long)(nums[dq.front()]-nums[start]);
                if(dq.front()==start){
                    dq.pop_front();
                }
                start++;
            }
            //cout<<start<<" "<<end<<" "<<reqOps<<endl;
            ans+=(end-start+1);
        }

        return ans;
    }
};
