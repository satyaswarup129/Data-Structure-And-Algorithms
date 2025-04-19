class FreqStack {
public:
    unordered_map<int, int> fmap;
    vector<vector<int>> fstack = {{}};
    
    void push(int x) {
        int freq = fmap[x] + 1;
        fmap[x] = freq;
        if (freq == fstack.size()) fstack.push_back(vector<int>());
        fstack[freq].push_back(x);
    }
    
    int pop() {
        int x = fstack.back().back();
        fstack.back().pop_back();
        if (fstack.back().empty()) fstack.pop_back();
        fmap[x]--;
        return x;
    }
};
