class Solution {
private:
    void dfs(string prefix, string &res, unordered_set<string> &visit, int &k) {
        for(int i = 0; i < k; i++) {
            string temp = prefix + to_string(i);
            if(visit.find(temp) != visit.end()) continue;
            visit.insert(temp);
            dfs(temp.substr(1, prefix.size()), res, visit, k);
            res += to_string(i);
        }
    }
public:
    string crackSafe(int n, int k) {
        if(n == 1 && k == 1) return "0";
        unordered_set<string> visit;
        string res, prefix(n-1, '0');
        dfs(prefix, res, visit, k);
        res += prefix;
        return res;
    }
};
