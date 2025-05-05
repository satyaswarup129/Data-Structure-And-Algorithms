class Router {
public:
    int sz;
    map<vector<int>,int>mp;
    map<int,vector<int>>mp1;
    deque<vector<int>>dq;
    Router(int memoryLimit) {
        sz=memoryLimit;
        mp.clear();
        mp1.clear();
        while(!dq.empty()){
            dq.pop_back();
        }
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        vector<int>v={source,destination,timestamp};
        if(mp.find(v)==mp.end()){
            mp[v]++;
            while(dq.size()==sz){
                mp.erase(dq.back());
                auto &it= mp1[dq.back()[1]];
                it.erase(it.begin(),it.begin()+1);
                 if(it.size()==0){
                mp1.erase(dq.back()[1]);
                 }
                dq.pop_back();
            }
            mp1[destination].push_back(timestamp);
            dq.push_front(v);
            return 1;
        }
        else{
            return 0;
        }
    }
    
    vector<int> forwardPacket() {
        vector<vector<int>>temp;
        if(!dq.empty()){
        temp.push_back(dq.back());
         mp.erase(dq.back());
        dq.pop_back();
        }
        if(temp.size()!=0){
            auto &it=mp1[temp[0][1]];
            it.erase(it.begin(),it.begin()+1);
            return temp[0];
        }
        return {};
      
    }
    
    int getCount(int destination, int startTime, int endTime) {
        if(mp1.find(destination)==mp1.end()){
            return 0;
        }
        auto &it=mp1[destination];
        int lb=lower_bound(it.begin(),it.end(),startTime)-it.begin();
        int ub=upper_bound(it.begin(),it.end(),endTime)-it.begin();
        ub--;
        int dist=ub-lb+1;
        return dist;
    }
};
