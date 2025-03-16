class LFUCache {
public:
    int size;
    map<int,list<vector<int>>>FreqList;
    unordered_map<int,list<vector<int>>::iterator>TrackList;
    LFUCache(int capacity) {
        this->size=capacity;
    }
    
    int get(int key) {
        if(TrackList.find(key)==TrackList.end()) return -1;

        int Freq=(*TrackList[key])[2];
        int value=(*TrackList[key])[1];
        FreqList[Freq].erase(TrackList[key]);
        if(FreqList[Freq].size()==0) FreqList.erase(Freq);
        Freq++;
        FreqList[Freq].push_front({key,value,Freq});
        TrackList[key]=FreqList[Freq].begin();
        return value;
    }
    
    void put(int key, int value) {
        if(TrackList.find(key)!=TrackList.end()){
            int Freq=(*TrackList[key])[2];
            FreqList[Freq].erase(TrackList[key]);
            if(FreqList[Freq].size()==0) FreqList.erase(Freq);
            Freq++;
            FreqList[Freq].push_front({key,value,Freq});
            TrackList[key]=FreqList[Freq].begin();
            return ;
        }
        if(TrackList.size()==size){
           auto& List=FreqList.begin()->second;
           auto it=(List).back();
           int temp=it[0];
           int Freq=it[2];
           (List).pop_back();
           TrackList.erase(temp);
           if(FreqList[Freq].size()==0) FreqList.erase(Freq);
        }
        FreqList[1].push_front({key,value,1});
        TrackList[key]=FreqList[1].begin();
        return ;
    }
};
