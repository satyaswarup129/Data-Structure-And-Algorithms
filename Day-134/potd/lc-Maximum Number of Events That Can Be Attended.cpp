class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end());
        int i=0,n=events.size(),ans=0,mxday=0;
        priority_queue<int,vector<int>,greater<int>> pq;
        for(auto it:events) mxday=max(mxday,it[1]);
        for(int day=1;day<=mxday;day+=1){
            while(i<n && events[i][0]<=day) pq.push(events[i++][1]);
            while(!pq.empty() && day>pq.top()) pq.pop();
            if(!pq.empty()){
                ans+=1;
                pq.pop();
            }
        }
        return ans;
    }
};
