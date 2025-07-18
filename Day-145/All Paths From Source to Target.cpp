class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& G) {
        vector<vector<int>> ans;
        queue<vector<int>> q;
        q.push({0});                                                   
        while(size(q)) {
            auto path = move(q.front()); q.pop();
            if(path.back() == size(G)-1) ans.push_back(move(path));    
            else
                for(auto child : G[path.back()]) {                    
                    path.push_back(child);
                    q.push(path);                                    
                    path.pop_back();
                }
        }
        return ans;
    }
};
