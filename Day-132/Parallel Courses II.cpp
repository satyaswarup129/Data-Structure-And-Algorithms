class Solution {
    struct Cmp {
        bool operator() (const vector<int> &a, vector<int> &b) {
            return a[1] < b[1];
        }
    };
    
    int dfs(vector<vector<int>> &edges, vector<int> &depths, int idx) {
        if (depths[idx] == -1) {
            int depth = 0;
            for (int e: edges[idx])
                depth = max(depth, dfs(edges, depths, e));
            depths[idx] = depth + 1;
        }
        return depths[idx];
    }
    
public:
    int minNumberOfSemesters(int n, vector<vector<int>>& dependencies, int k) {
        vector<int> degrees(n);
        vector<vector<int>> edges(n);
        for (auto &dep: dependencies) {
            degrees[dep[1]-1]++;
            edges[dep[0]-1].push_back(dep[1]-1);
        }
        vector<int> depths(n, -1);
        for (int i=0; i<n; i++)
            dfs(edges, depths, i);  // compute depth for each node
        
        priority_queue<vector<int>, vector<vector<int>>, Cmp> mqueue;  // priority_queue is based on depth of each node
        for (int i=0; i<n; i++) {
            if (degrees[i] == 0)
                mqueue.push({i, depths[i]});   // only put nodes that have indegree 0 in the priority_queue
        }
        
        int step = 0;
        while (!mqueue.empty()) {
            step++;
            vector<vector<int>> next;
            for (int i=0, j=mqueue.size(); i<k && j>0; i++, j--) {  // stop the current round when the queue is empty or "k" limit is reached
                vector<int> top = mqueue.top();
                mqueue.pop();
                for (int e: edges[top[0]]) {
                    if (--degrees[e] == 0) {
					    // note that, we can't simply put it in the priority_queue, otherwise it may be picked up in the current round
                        next.push_back({e, depths[e]});
                    }
                }
            }
            for (auto it: next)
                mqueue.push(it);
        }
        
        return step;
    }
};
